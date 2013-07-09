header {
    package com.eprosima.rpcdds.idl.grammar;
    
    import com.eprosima.rpcdds.idl.grammar.Context;
    import com.eprosima.rpcdds.templates.TemplateManager;
    import com.eprosima.rpcdds.templates.TemplateGroup;
    import com.eprosima.rpcdds.templates.TemplateUtil;
    import com.eprosima.rpcdds.typecode.*;
    import com.eprosima.rpcdds.tree.*;
    import com.eprosima.rpcdds.util.Pair;
    import com.eprosima.rpcdds.util.Utils;
    
    import org.antlr.stringtemplate.StringTemplate;
   
    import java.util.Vector;
    import java.util.List;
    import java.util.ArrayList;
    import java.util.Map;
    import java.util.HashMap;
 }

class IDLParser extends Parser;
options {
	exportVocab=IDL;
	k=4;
}

{    
    private TemplateManager tmanager = null;
    private Context ctx = null;
}

specification [String outdir, String idlFilename, boolean replace] returns [boolean returnedValue = false]
{
    // Create initial context.
    ctx = new Context(idlFilename);
    
    // Create template manager
    tmanager = new TemplateManager("com/eprosima/rpcdds/idl/templates");
    // Load template to generate IDL for topics.
    tmanager.addGroup("TopicsIDL");
    // Load template to generate Utils for topics.
    tmanager.addGroup("UtilsHeader");
    tmanager.addGroup("UtilsSource");
    // Load template to generate Proxy for topics.
    tmanager.addGroup("ProxyHeader");
    tmanager.addGroup("ProxySource");
    // Load template to generate example to use Proxies.
    tmanager.addGroup("ClientExample");
    // Load template to generate proxy RPC support files.
    tmanager.addGroup("ClientRPCSupportHeader");
    tmanager.addGroup("ClientRPCSupportSource");
    // Load template to generate proxy async support files.
    tmanager.addGroup("AsyncSupportHeader");
    tmanager.addGroup("AsyncSupportSource");
    // Load template to generate Server for topics.
    tmanager.addGroup("ServerHeader");
    tmanager.addGroup("ServerSource");
    // Create main template for all templates.
    TemplateGroup maintemplates = tmanager.createTemplateGroup("main");
    maintemplates.setAttribute("ctx", ctx);
    
    //! Used to catch each definition grammar element in the whole IDL file.
    Pair<Definition, TemplateGroup> dtg = null;
    
    // TODO Guardar declaraciones en el contexto.
}
	:   (import_dcl)* (dtg=definition{maintemplates.setAttribute("definitions", dtg.second()); ctx.addDefinition(dtg.first());})+
{
    // Zone used to write all files using the generated string templates.
    System.out.println("Generating Utils Code...");
    if(Utils.writeFile(outdir + idlFilename + "RequestReply.idl", maintemplates.getTemplate("TopicsIDL"), replace))
    {
        if(Utils.writeFile(outdir + idlFilename + "RequestReplyUtils.h", maintemplates.getTemplate("UtilsHeader"), replace))
        {
            if(Utils.writeFile(outdir + idlFilename + "RequestReplyUtils.cxx", maintemplates.getTemplate("UtilsSource"), replace))
            {
                System.out.println("Generating Proxy Code...");
                if(Utils.writeFile(outdir + idlFilename + "Proxy.h", maintemplates.getTemplate("ProxyHeader"), replace))
                {
                    if(Utils.writeFile(outdir + idlFilename + "Proxy.cxx", maintemplates.getTemplate("ProxySource"), replace))
                    {
                        if(Utils.writeFile(outdir + "Client.cxx", maintemplates.getTemplate("ClientExample"), replace))
                        {
                            if(Utils.writeFile(outdir + idlFilename + "ClientRPCSupport.h", maintemplates.getTemplate("ClientRPCSupportHeader"), replace))
                            {
                                if(Utils.writeFile(outdir + idlFilename + "ClientRPCSupport.cxx", maintemplates.getTemplate("ClientRPCSupportSource"), replace))
                                {
                                    if(Utils.writeFile(outdir + idlFilename + "AsyncSupport.h", maintemplates.getTemplate("AsyncSupportHeader"), replace))
                                    {
                                        if(Utils.writeFile(outdir + idlFilename + "AsyncSupport.cxx", maintemplates.getTemplate("AsyncSupportSource"), replace))
                                        {
                                            System.out.println("Generating Server Code...");
                                            if(Utils.writeFile(outdir + idlFilename + "Server.h", maintemplates.getTemplate("ServerHeader"), replace))
                                            {
                                                if(Utils.writeFile(outdir + idlFilename + "Server.cxx", maintemplates.getTemplate("ServerSource"), replace))
                                                {
                                                    returnedValue = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
	;

/*!
 * @brief This grammar element represents a global definition: type declaration, interface, module, etc...
 * @return A pair with the object that represents the definition (interface for other objects like module grammar element)
 * and the template group generated by the definition (in fact the template group generated by the element who inherits).
 */
definition returns [Pair<Definition, TemplateGroup> dtg = null]
{
    // TODO Cambiar esto. No me gusta la forma.
    Pair<TypeDeclaration, TemplateGroup> tdtg = null;
    Pair<Module, TemplateGroup> mtg = null;
    Pair<Interface, TemplateGroup> itg = null;
}
	:   (   tdtg=type_dcl SEMI! {dtg = new Pair<Definition, TemplateGroup>(tdtg.first(), tdtg.second());}  // Type Declaration
	    |   const_dcl SEMI!
	    |   except_dcl SEMI!
	    |   (("abstract" | "local")? "interface") => itg=interf SEMI! {dtg = new Pair<Definition, TemplateGroup>(itg.first(), itg.second());} // Interface
	    |   mtg=module SEMI! {dtg = new Pair<Definition, TemplateGroup>(mtg.first(), mtg.second());} // Module
	    |   (("abstract" | "custom")? "valuetype") => value SEMI!
	    |   type_id_dcl SEMI!
	    |   type_prefix_dcl SEMI!
	    |   (("abstract" | "custom")? "eventtype") => event SEMI!
	    |   component SEMI!
	    |   home_dcl SEMI!
	    )
	;

/*!
 * @brief This grammar expression catches a module definition.
 * @return This grammar expression returns the Module object as DefinitionContainer to be stored.
 * Also the TemplateGroup of module is returned.
 */
module returns [Pair<Module, TemplateGroup> returnPair = null]
{
    Module moduleObject = null;
    TemplateGroup moduleTemplates = tmanager.createTemplateGroup("module");
    TemplateGroup tg = null;
    // Store old namespace.
    String name = null, old_scope = ctx.getScope();
}
	:    "module"^
	     name=identifier
	     {
	       // Create the Module object.
	       moduleObject = new Module(name);
	       // Set the module object to the TemplateGroup of the module.
	       moduleTemplates.setAttribute("module", moduleObject);
	       // Update to a new namespace.
	       ctx.setScope(old_scope + name + "::");
	     }
	     // Each definition is stored in the Module and each TemplateGroup is set as attribute in the TemplateGroup of the module.
	     LCURLY! tg=d:definition_list[moduleObject]{moduleTemplates.setAttribute("definition_list", tg);} RCURLY!
	     {
	       // Set the old namespace.
	       ctx.setScope(old_scope);
	       // Create the returned data.
	       returnPair = new Pair<Module, TemplateGroup>(moduleObject, moduleTemplates);
	     }
	;

/*!
 * @brief This grammar expression catches a list of definitions.
 * @param dc An object that inherits from DefinitionContainer. This object could store all definitions.
 * @return This grammar expression returns the template group with all template groups of definitions.
 */
definition_list [DefinitionContainer dc] returns [TemplateGroup dlTemplates = tmanager.createTemplateGroup("definition_list")]
{
    Pair<Definition, TemplateGroup> dtg = null;
}
	:   (dtg=definition{dc.add(dtg.first()); dlTemplates.setAttribute("definitions", dtg.second());})+
	;

/*!
 * @brief This grammar expression catches currently a interface declaration.
 * @return This grammar expression returns the interface object and its template group.
 */
interf returns [Pair<Interface, TemplateGroup> itg = null]
    : ( itg=interface_dcl
      | forward_dcl
      )
    ;
 
// Grammar changed to differentiate between 
// forward declared interfaces and empty interfaces
/*!
 * @brief This grammar expression catches a interface declaration.
 * @return This grammar expression returns the interface object and its template group.
 */
interface_dcl returns [Pair<Interface, TemplateGroup> returnPair = null]
    {
        Interface interfaceObject = null;
        TemplateGroup interfaceTemplates = tmanager.createTemplateGroup("interface");
        TemplateGroup tg = null;
        String name = null;
    }
	:   (( "abstract" | "local" )?
 	    "interface"^
 	    name=identifier
 	    {
           // Create the Module object.
           interfaceObject = new Interface(ctx.getScope(), name);
           // Set the the interface object to the TemplateGroup of the module.
           interfaceTemplates.setAttribute("interface", interfaceObject);
        }
	    ( interface_inheritance_spec )?	   
	    LCURLY tg=interface_body[interfaceObject]{interfaceTemplates.setAttribute("export_list", tg);} RCURLY)
	    {
           // Create the returned data.
           returnPair = new Pair<Interface, TemplateGroup>(interfaceObject, interfaceTemplates);
        }
	;
	
forward_dcl
 	:    ( "abstract" | "local" )?
 	    "interface"^
 	    identifier
 	;

/*!
 * @brief This grammar expression catches a list of exports.
 * @param dc An object that inherits from ExportContainer. This object could store all exports.
 * @return This grammar expression returns the template group with all template groups of exports.
 */
interface_body [ExportContainer ec] returns [TemplateGroup elTemplates = tmanager.createTemplateGroup("export_list")]
    {
        Pair<Export, TemplateGroup> etg = null;
    }
	:   ( etg=export{ec.add(etg.first()); elTemplates.setAttribute("exports", etg.second());} )*
	;

/*!
 * @brief This grammar element represents an export of a interface: type declaration, operation, etc...
 * @return A pair with the object that represents the export (interface for other objects like operation grammar element)
 * and the template group generated by the export (in fact the template group generated by the element who inherits).
 */
export returns [Pair<Export, TemplateGroup> etg = null]
    {
        // TODO Cambiar esto. No me gusta la forma.
        Pair<TypeDeclaration, TemplateGroup> tetg = null;
        Pair<Operation, TemplateGroup> oetg = null;
    }
	:   (   tetg=type_dcl SEMI! {etg = new Pair<Export, TemplateGroup>(tetg.first(), tetg.second());}  // Type Declaration
	    |   const_dcl SEMI!
	    |   except_dcl SEMI!
	    |   attr_dcl SEMI!
	    |   oetg=op_dcl SEMI! {etg = new Pair<Export, TemplateGroup>(oetg.first(), oetg.second());}  // Operation
	    |   type_id_dcl SEMI!
	    |   type_prefix_dcl SEMI!
	    )
	;


interface_inheritance_spec
	:   COLON^ scoped_name_list
	;

interface_name
	:   scoped_name
	;

scoped_name_list
	:    scoped_name (COMMA! scoped_name)*
	;


scoped_name returns [String literal = ""]
    {
        String aux = null;
    }
	:  ({literal += LT(1).getText();} SCOPEOP^ )?
	   {literal += LT(1).getText();} IDENT^ /* identifier */
	   ({literal += LT(1).getText();} SCOPEOP! aux=identifier{literal += aux;})*
	;

value
	:   ( value_dcl
	    | value_abs_dcl
	    | value_box_dcl
	    | value_custom_dcl
	    | value_forward_dcl
	    )
	;

value_forward_dcl
	:   "valuetype"^
	    identifier
	;

value_box_dcl
	:   "valuetype"^
	    identifier
	    type_spec
	;

value_abs_dcl
	:   "abstract"
	    "valuetype"^
	    identifier
	    ( value_abs_full_dcl
	    | // value_abs_forward_dcl
	    )
	;

value_abs_full_dcl
	:   value_inheritance_spec
	    LCURLY! ( export )* RCURLY!
	;

// value_abs_forward_dcl
// 	:
// 	;

value_dcl
	:   value_header
	    LCURLY! ( value_element )* RCURLY!
	;

value_custom_dcl
	:   "custom"^
	    value_dcl
	;

value_header
	:   "valuetype"^
	    identifier
	    value_inheritance_spec
	;

value_inheritance_spec
/*
	:   ( COLON ( "truncatable" )?
	      value_name ( COMMA! value_name )*
	    )?
	    ( "supports" interface_name ( COMMA! interface_name )* )?
	;
*/
	:   ( value_value_inheritance_spec )?
	    ( value_interface_inheritance_spec )?
	;

value_value_inheritance_spec
	:   COLON^ ( "truncatable" )?
	    value_name ( COMMA! value_name )*
	;

value_interface_inheritance_spec
	:   "supports"^ interface_name ( COMMA! interface_name )*
	;

value_name
	:   scoped_name
	;

value_element
	:   ( export
	    | state_member
	    | init_dcl
	    )
	;

state_member
	:   ( "public" | "private" )
	    type_spec declarators SEMI!
	;

init_dcl
	:   "factory"^ identifier
	    LPAREN! (init_param_decls)? RPAREN!
	    (raises_expr)?
	    SEMI!
	;

init_param_decls
	:   init_param_decl ( COMMA! init_param_decl )*
	;

init_param_decl
	:   init_param_attribute
	    param_type_spec
	    simple_declarator
	;

init_param_attribute
	:   "in"
	;

const_dcl
	:   "const"^ const_type identifier ASSIGN! const_exp
	;

const_type
	:   (integer_type) => integer_type
	|   char_type
	|   wide_char_type
	|   boolean_type
	|   floating_pt_type
	|   string_type
	|   wide_string_type
	|   fixed_pt_const_type
	|   scoped_name
	|   octet_type
	;


/*   EXPRESSIONS   */

const_exp returns [String literal = null]
	:   literal=or_expr
	;

or_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=xor_expr
	    (  {literal += LT(1).getText();}
	       OR^ // or_op
	       aux=xor_expr
	       {literal += aux;}
	    )*
	;

// or_op
// 	:    OR
// 	;


xor_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=and_expr
	    (
	       {literal += LT(1).getText();}
	       XOR^ // xor_op
	       aux=and_expr
	       {literal += aux;}
	    )*
	;

// xor_op
// 	:    XOR
// 	;

and_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=shift_expr
	    (
	       {literal += LT(1).getText();}
	       AND^ // and_op
	       aux=shift_expr
	       {literal += aux;}
	    )*
	;

// and_op
// 	:    AND
// 	;


shift_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=add_expr
	    (
	       {literal += LT(1).getText();}
	       ( LSHIFT^
	       | RSHIFT^
	       ) // shift_op
	       aux=add_expr
	       {literal += aux;}
	    )*
	;

// shift_op
// 	:    LSHIFT
// 	|    RSHIFT
// 	;


add_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=mult_expr
	    (
	       {literal += LT(1).getText();}
	       ( PLUS^
	       | MINUS^
	       ) // add_op
	       aux=mult_expr
	       {literal += aux;}
	    )*
	;

// add_op
// 	:    PLUS
// 	|    MINUS
// 	;

mult_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=unary_expr
	    (
	       {literal += LT(1).getText();}
	       ( STAR^
	       | DIV^
	       | MOD^
	       ) // mult_op
	       aux=unary_expr
	       {literal += aux;}
	    )*
	;

// mult_op
// 	:    STAR
// 	|    DIV
// 	|    MOD
// 	;

unary_expr returns [String literal = null]
{
    String aux = null;
}
	:  
	   {literal = LT(1).getText();} 
	   ( MINUS^
	   | PLUS^
	   | TILDE^
	   ) // unary_operator
	    aux=primary_expr
	    {literal += aux;}
	|   literal=primary_expr
	;

// unary_operator
// 	:   MINUS
// 	|   PLUS
// 	|   TILDE
// 	;

// Node of type TPrimaryExp serves to avoid inf. recursion on tree parse
primary_expr returns [String lit = null]
{
    String aux = null;
}
	:   lit=scoped_name
	|   lit=literal
	|  {lit = LT(1).getText();}  
	   LPAREN^
	   aux=const_exp
	   {lit += aux; lit += LT(1).getText();}
	   RPAREN
	;

literal returns [String lit = null]
	:   lit=integer_literal
	|   lit=string_literal
	|   lit=wide_string_literal
	|   lit=character_literal
	|   lit=wide_character_literal
	|   lit=fixed_pt_literal
	|   lit=floating_pt_literal
	|   lit=boolean_literal
	;

boolean_literal returns [String lit = null]
	:   "TRUE"{lit = "true";}
	|   "FALSE"{lit = "false";}
	;

positive_int_const returns [String literal = null]
	:    literal=const_exp
	;


type_dcl returns [Pair<TypeDeclaration, TemplateGroup> returnPair = null]
{
    Pair<TypeCode, TemplateGroup> ttg = null;
}
	:
	(
	   "typedef"^ type_declarator
	|   (struct_type) => ttg=struct_type
	|   (union_type) => ttg=union_type
	|   ttg=enum_type
	|   "native"^ simple_declarator
	|   constr_forward_decl
	)
	{
	    returnPair = new Pair<TypeDeclaration, TemplateGroup>(new TypeDeclaration(ttg.first()), ttg.second());
	}
	;

type_declarator
	:   type_spec declarators
	;

type_spec returns [TypeCode typecode = null]
	:   typecode=simple_type_spec
	|   constr_type_spec
	;

simple_type_spec returns [TypeCode typecode = null]
{
    String literal = null;
} 
	:   typecode=base_type_spec
	|   typecode=template_type_spec
	|	literal=scoped_name
	   {
	       // Find typecode in the global map.
	       typecode = ctx.getTypeCode(literal);
	       
	       if(typecode == null)
	           System.out.println("ERROR: Cannot find the typecode for " + literal);
	   }
	;

base_type_spec returns [TypeCode typecode = null]
	:   (floating_pt_type) => typecode=floating_pt_type	
	|   typecode=integer_type	
	|   typecode=char_type		
	|   typecode=wide_char_type		
	|   typecode=boolean_type	
	|   typecode=octet_type
	|   any_type
	|   object_type
	|   value_base_type
	;

template_type_spec returns [TypeCode typecode = null]
	:   typecode=sequence_type
	|   typecode=string_type
	|   typecode=wide_string_type
	|   fixed_pt_type
	;

constr_type_spec
	:   struct_type
	|   union_type
	|   enum_type
	;

declarators returns [Vector<Pair<String, ContainerTypeCode>> declvector = new Vector<Pair<String, ContainerTypeCode>>()]
{
    Pair<String, ContainerTypeCode> pair = null;
}
	:   pair=declarator{declvector.add(pair);} (COMMA! pair=declarator{declvector.add(pair);})*
	;

declarator returns [Pair<String, ContainerTypeCode> pair = null]
	:   pair=simple_declarator
	|   pair=complex_declarator
	;

simple_declarator returns [Pair<String, ContainerTypeCode> pair = null]
{
    String name = null;
}
	:  name=identifier
	   {
	       pair = new Pair<String, ContainerTypeCode>(name, null);
	   }
	;

complex_declarator returns [Pair<String, ContainerTypeCode> pair = null]
	:   pair=array_declarator
	;

floating_pt_type returns [TypeCode typecode = null]
	:   "float"{typecode = new PrimitiveTypeCode(TypeCode.KIND_FLOAT);}
	|   "double"{typecode = new PrimitiveTypeCode(TypeCode.KIND_DOUBLE);}
	|   "long"^ "double"{typecode = new PrimitiveTypeCode(TypeCode.KIND_LONGDOUBLE);}
	;

integer_type returns [TypeCode typecode = null]
	:  typecode=signed_int
	|  typecode=unsigned_int
	;

signed_int returns [TypeCode typecode = null]
	:  typecode=signed_short_int
	|  typecode=signed_long_int
	|  typecode=signed_longlong_int
	;

signed_short_int returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_SHORT)]
	:  "short"
	;

signed_long_int returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_LONG)]
	:  "long"
	;

signed_longlong_int returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_LONGLONG)]
	:  "long" "long"
	;

unsigned_int returns [TypeCode typecode = null]
	:  typecode=unsigned_short_int
	|  typecode=unsigned_long_int
	|  typecode=unsigned_longlong_int
	;

unsigned_short_int returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_USHORT)]
	:  "unsigned" "short"
	;

unsigned_long_int returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_ULONG)]
	:  "unsigned" "long"
	;

unsigned_longlong_int returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_ULONGLONG)]
	:  "unsigned" "long" "long"
	;

char_type returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_CHAR)]
	:   "char"
	;

wide_char_type returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_WCHAR)]
	:   "wchar"
	;

boolean_type returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_BOOLEAN)]
	:   "boolean"
	;

octet_type returns [TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_OCTET)]
	:   "octet"
	;

any_type
	:   "any"
	;

object_type
	:   "Object"
	;

struct_type returns [Pair<TypeCode, TemplateGroup> returnPair = null]
{
    String name = null;
    StructTypeCode structTP = null;
    TemplateGroup structTemplates = tmanager.createTemplateGroup("struct_type");
}
	:   "struct"^
	    name=identifier
	    {
	       structTP = new StructTypeCode(ctx.getScope(), name);
	    }
	    LCURLY! member_list[structTP] RCURLY!
	    {
	       structTemplates.setAttribute("ctx", ctx);
           structTemplates.setAttribute("struct", structTP);
           // Add struct typecode to the map with all typecodes.
           ctx.addTypeCode(structTP.getScopedname(), structTP);
           // Return the returned data.
           returnPair = new Pair<TypeCode, TemplateGroup>(structTP, structTemplates);
	    }
	;

member_list [StructTypeCode structTP]
{
    Vector<Pair<String, TypeCode>> declvector = null;
}
	:   (
	       declvector=member
	       {
	           for(int count = 0; count < declvector.size(); ++count)
	               structTP.addMember(new StructMember(declvector.get(count).second(), declvector.get(count).first()));
	       }
	    )+
	;

member returns [Vector<Pair<String, TypeCode>> newVector = new Vector<Pair<String, TypeCode>>()]
{
    Vector<Pair<String, ContainerTypeCode>> declvector = null;
    TypeCode typecode = null;
}
	:  typecode=type_spec declvector=declarators SEMI!
	   {
	       for(int count = 0; count < declvector.size(); ++count)
	       {
	           if(declvector.get(count).second() != null)
	           {
	               // Array declaration
	               declvector.get(count).second().setContentTypeCode(typecode);
	               newVector.add(new Pair<String, TypeCode>(declvector.get(count).first(), declvector.get(count).second()));
	           }
	           else
	           {
	               // Simple declaration
	               newVector.add(new Pair<String, TypeCode>(declvector.get(count).first(), typecode));
	           }
	       }
	   }
	;

union_type returns [Pair<TypeCode, TemplateGroup> returnPair = null]
{
    String name = null;
    TypeCode dist_type = null;
    UnionTypeCode unionTP = null;
    TemplateGroup unionTemplates = tmanager.createTemplateGroup("union_type");
}
	:   "union"^
	    name=identifier
	    "switch"! LPAREN! dist_type=switch_type_spec RPAREN!
	    {
	       unionTP = new UnionTypeCode(ctx.getScope(), name, dist_type);
	    }
	    LCURLY! switch_body[unionTP] RCURLY!
	    {
	       // Calculate default label.
	       unionTP.setDefaultvalue(TemplateUtil.getUnionDefaultLabel(unionTP.getDiscriminator(), unionTP.getMembers()));
	       unionTemplates.setAttribute("ctx", ctx);
           unionTemplates.setAttribute("union", unionTP);
           
           // Add union typecode to the map with all typecodes.
           ctx.addTypeCode(unionTP.getScopedname(), unionTP);
           // Return the returned data.
           returnPair = new Pair<TypeCode, TemplateGroup>(unionTP, unionTemplates);
        }
	;

switch_type_spec returns [TypeCode typecode = null]
{
    String literal = null;
}
	:   typecode=integer_type
	|   typecode=char_type
	|   typecode=boolean_type
	|   enum_type
	|   literal=scoped_name
	   {
           // Find typecode in the global map.
           typecode = ctx.getTypeCode(literal);
           
           if(typecode == null)
               System.out.println("ERROR: Cannot find the typecode for " + literal);
       }
	;

switch_body [UnionTypeCode unionTP]
	:   case_stmt_list[unionTP]
	;

case_stmt_list [UnionTypeCode unionTP]
	:  (case_stmt[unionTP])+
	;

case_stmt [UnionTypeCode unionTP]
{
    Pair<String, TypeCode> element = null;
    String label = null;
    boolean defaul = false;
    UnionMember member = new UnionMember();
}
	:   // case_label_list
	    ( "case"^ label=const_exp{member.addLabel(label);} COLON!
	    | "default"^ {defaul = true;} COLON!
	    )+
	    element=element_spec SEMI!
	    {
	       member.setTypecode(element.second());
	       member.setName(element.first());
	       int index = unionTP.addMember(member);
	       if(defaul) unionTP.setDefaultindex(index);
	    }
	;

// case_label_list
// 	:   (case_label)+
// 	;


// case_label
// 	:   "case"^ const_exp COLON!
// 	|   "default"^ COLON!
// 	;

element_spec returns [Pair<String, TypeCode> newpair = null]
{
    Pair<String, ContainerTypeCode> decl = null;
    TypeCode typecode = null;
}
	:   typecode=type_spec decl=declarator
	    {
            if(decl.second() != null)
            {
                decl.second().setContentTypeCode(typecode);
                newpair = new Pair<String, TypeCode>(decl.first(), decl.second());
            }
            else
            {
                newpair = new Pair<String, TypeCode>(decl.first(), typecode);
            }
        }
	;

enum_type returns [Pair<TypeCode, TemplateGroup> returnPair = null]
{
    String name = null;
    EnumTypeCode enumTP = null;
    TemplateGroup enumTemplates = tmanager.createTemplateGroup("enum_type");
}
	:  "enum"^
	   name=identifier
	   {
	       enumTP = new EnumTypeCode(ctx.getScope(), name);
	   }
	   LCURLY! enumerator_list[enumTP] RCURLY!
	   {
           enumTemplates.setAttribute("ctx", ctx);
           enumTemplates.setAttribute("enum", enumTP);
           // Add enum typecode to the map with all typecodes.
           ctx.addTypeCode(enumTP.getScopedname(), enumTP);
           // Return the returned data.
           returnPair = new Pair<TypeCode, TemplateGroup>(enumTP, enumTemplates);
	   }
	;

enumerator_list [EnumTypeCode enumTP]
	:    enumerator[enumTP] (COMMA! enumerator[enumTP])*
	;

enumerator [EnumTypeCode enumTP]
{
    String name = null;
}
	:   name=identifier{enumTP.addMember(new EnumMember(name));}
	;

sequence_type returns [SequenceTypeCode typecode = null]
{
    TypeCode type = null;
    String maxsize = null;
}
	:  "sequence"^
	    LT! type=simple_type_spec maxsize=opt_pos_int GT!
	    {
	       typecode = new SequenceTypeCode(maxsize);
	       typecode.setContentTypeCode(type);
	    }
	;

opt_pos_int returns [String literal = null]
	:    (COMMA! literal=positive_int_const)?
	;

string_type returns [TypeCode typecode = null]
{
    String maxsize = null;
}
	:  "string"^ (LT! maxsize=positive_int_const GT!)?
	   {typecode = new StringTypeCode(TypeCode.KIND_STRING, maxsize);}
	;

wide_string_type returns [TypeCode typecode = null]
{
    String maxsize = null;
}
	:  "wstring"^ (LT! maxsize=positive_int_const GT!)?
	   {typecode = new StringTypeCode(TypeCode.KIND_WSTRING, maxsize);}
	;

array_declarator returns [Pair<String, ContainerTypeCode> pair = null]
{
    String name = LT(1).getText(), size = null;
    ArrayTypeCode typecode = new ArrayTypeCode();
}
	:   IDENT^					// identifier
	    (
	       size=fixed_array_size
	       {
	           typecode.addDimension(size);
	       }
	    )+
	    {
	       pair = new Pair<String, ContainerTypeCode>(name, typecode);
	    }
	;

fixed_array_size returns [String literal = null]
	:   LBRACK! literal=positive_int_const RBRACK!
	;

attr_dcl
	:   readonly_attr_spec
	|   attr_spec
	;

except_dcl
	:   "exception"^
	    identifier
	    LCURLY! opt_member_list RCURLY!
	;


opt_member_list
	:    (member)*
	;

 /*!
 * @brief This grammar expression catches a operation.
 * @return This grammar expression returns the operation object and its template group.
 */
op_dcl returns [Pair<Operation, TemplateGroup> returnPair = null]
    {
        Operation operationObject = null;
        TemplateGroup operationTemplates = tmanager.createTemplateGroup("operation");
        TemplateGroup tpl = null;
        String name = "";
        boolean oneway = false;
        TypeCode retType = null;
    }
	:   (oneway=op_attribute)?
	    retType=op_type_spec
	    {name += LT(1).getText();}IDENT^				// identifier
	    {
           // Create the Operation object.
           operationObject = new Operation(name);
           // Set the the interface object to the TemplateGroup of the module.
           operationTemplates.setAttribute("operation", operationObject);
           
           // Set return type
           operationObject.setRettype(retType);
           
           // Set oneway
           if(oneway) operationObject.setOneway(true);
        }
	    tpl=parameter_dcls[operationObject]
	    (raises_expr)?
	    (context_expr)?
	    {
	       // Store the parameter list template group in the operation template group.
	       operationTemplates.setAttribute("param_list", tpl);
           // Create the returned data.
           returnPair = new Pair<Operation, TemplateGroup>(operationObject, operationTemplates);
        }
	;

op_attribute returns [boolean ret = false]
	:   "oneway" {ret = true;}
	;

op_type_spec returns [TypeCode typecode = null]
	:   typecode=param_type_spec
	|   "void"
	;

parameter_dcls [Operation operation] returns [TemplateGroup tpl = tmanager.createTemplateGroup("param_list")]
	:   LPAREN! (param_dcl_list[operation, tpl])? RPAREN!
	;

param_dcl_list [Operation operation, TemplateGroup tpl]
    {
        Pair<Param, TemplateGroup> ptg = null;
    }
	:   ptg=param_dcl{operation.add(ptg.first()); tpl.setAttribute("parameters", ptg.second());}
	    (COMMA! ptg=param_dcl{operation.add(ptg.first()); tpl.setAttribute("parameters", ptg.second());})*
	;

param_dcl returns [Pair<Param, TemplateGroup> returnPair = null]
    {
        TemplateGroup paramTemplate = tmanager.createTemplateGroup("param");
        Pair<String, ContainerTypeCode> pair = null;
        TypeCode typecode = null;
        String literal = LT(1).getText();
    }
	:   ("in"^ | "out"^ | "inout"^)		// param_attribute
	    typecode=param_type_spec pair=simple_declarator
	    {
	        Param param = null;
	        if(literal.equals("in"))
	            param = new InputParam(pair.first(), typecode);
	        else if(literal.equals("out"))
	            param = new OutputParam(pair.first(), typecode);
	        else if(literal.equals("inout"))
	            param = new InoutParam(pair.first(), typecode);
	            
	        paramTemplate.setAttribute("parameter", param);
	        returnPair = new Pair<Param, TemplateGroup>(param, paramTemplate);
	    }
	;

// param_attribute
// 	:   "in"
// 	|   "out"
// 	|   "inout"
// 	;

raises_expr
	:   "raises"^ LPAREN! scoped_name_list RPAREN!
	;

context_expr
	:   "context"^ LPAREN! string_literal_list RPAREN!
	;

string_literal_list
	:    string_literal (COMMA! string_literal)*
	;

param_type_spec returns [TypeCode typecode = null]
    {
        String literal = null;
    }
	:   typecode=base_type_spec
	|   typecode=string_type
	|   typecode=wide_string_type
	|   literal=scoped_name
	   {
           // Find typecode in the global map.
           typecode = ctx.getTypeCode(literal);
           
           if(typecode == null)
               System.out.println("ERROR: Cannot find the typecode for " + literal);
       }
	;

fixed_pt_type
	:   "fixed"^ LT! positive_int_const COMMA! positive_int_const GT!
	;

fixed_pt_const_type
	:   "fixed"
	;

value_base_type
	:   "ValueBase"
	;

constr_forward_decl
	:   "struct"^ identifier
	|   "union"^ identifier
	;

import_dcl
	:   "import"^ imported_scope SEMI!
	;

imported_scope
	:   scoped_name
	|   string_literal
	;

type_id_dcl
	:   "typeid"^
	    scoped_name
	    string_literal
	;

type_prefix_dcl
	:   "typeprefix"^
	    scoped_name
	    string_literal
	;

readonly_attr_spec
	:   "readonly" "attribute"^
	    param_type_spec
	    readonly_attr_declarator
	;

readonly_attr_declarator
	:   simple_declarator
	    ( raises_expr
	    | (COMMA! simple_declarator)*
	    )
	;

attr_spec
	:   "attribute"^ param_type_spec attr_declarator
	;

attr_declarator
	:   simple_declarator
	    ( ("getraises" | "setraises") => attr_raises_expr
	    | (COMMA! simple_declarator)*
	    )
	;

attr_raises_expr
	:   (get_excep_expr)?
	    (set_excep_expr)?
	;

get_excep_expr
	:   "getraises"^ exception_list
	;

set_excep_expr
	:   "setraises"^ exception_list
	;

exception_list
	:   LPAREN! scoped_name (COMMA! scoped_name)* RPAREN!
	;

// Component Stuff

component
	:   "component"^
	    identifier
	    (component_dcl)?
	;

component_dcl
	:   (component_inheritance_spec)?
	    (supported_interface_spec)?
	    LCURLY! component_body RCURLY!
	;

supported_interface_spec
	:   "supports"^ scoped_name ( COMMA! scoped_name )*
	;

component_inheritance_spec
	:   COLON^ scoped_name
	;

component_body
	:   (component_export)*
	;

component_export
	:   ( provides_dcl SEMI!
	    | uses_dcl SEMI!
	    | emits_dcl SEMI!
	    | publishes_dcl SEMI!
	    | consumes_dcl SEMI!
	    | attr_dcl SEMI!
	    )
	;

provides_dcl
	:   "provides"^ interface_type identifier
	;

interface_type
	:   ( scoped_name
	    | "Object"
	    )
	;

uses_dcl
	:   "uses"^ ("multiple")? interface_type identifier
	;

emits_dcl
	:   "emits"^ scoped_name identifier
	;

publishes_dcl
	:   "publishes"^ scoped_name identifier
	;

consumes_dcl
	:   "consumes"^ scoped_name identifier
	;

home_dcl
	:   home_header home_body
	;

home_header
	:   "home"^ identifier
	    (home_inheritance_spec)?
	    (supported_interface_spec)?
	    "manages"! scoped_name
	    (primary_key_spec)?
	;

home_inheritance_spec
	:   COLON^ scoped_name
	;

primary_key_spec
	:   "primarykey"^ scoped_name
	;

home_body
	:   LCURLY! (home_export)* RCURLY!
	;

home_export
	:   ( export
	    | factory_dcl SEMI!
	    | finder_dcl SEMI!
	    )
	;

factory_dcl
	:   "factory"^ identifier
	    LPAREN! init_param_decls RPAREN!
	    (raises_expr)?
	;

finder_dcl
	:   "finder"^ identifier
	    LPAREN! init_param_decls RPAREN!
	    (raises_expr)?
	;

event
	:   ( event_abs
	    | event_custom
	    | event_dcl
	    )
	;

event_header
	:   "eventtype"^
	    identifier
	;

event_abs
	:   "abstract"^
	    event_header
	    (event_abs_dcl)?
	;

event_abs_dcl
	:   value_inheritance_spec
	    LCURLY! (export)* RCURLY!
	;

event_custom
	:   "custom"^
	    event_header
	    event_elem_dcl
	;

event_dcl
	:   event_header
	    ( event_elem_dcl
	    | // event_forward_dcl
	    )
	;

event_elem_dcl
	:   value_inheritance_spec
	    LCURLY! (export)* RCURLY!
	;

// event_forward_dcl
// 	:
// 	;

/* literals */
integer_literal returns [String literal = LT(1).getText()]
	:   INT
	|   OCTAL
	|   HEX
	;

string_literal returns [String literal = ""]
	:  (
	       {literal += LT(1).getText();}
	       STRING_LITERAL
	   )+
	;

wide_string_literal returns [String literal = ""]
	:  (
	       {literal += LT(1).getText();}
	       WIDE_STRING_LITERAL
	   )+
	;

character_literal returns [String literal = LT(1).getText()]
	:  CHAR_LITERAL
	;

wide_character_literal returns [String literal = LT(1).getText()]
	:  WIDE_CHAR_LITERAL
	;

fixed_pt_literal returns [String literal = LT(1).getText()]
	:  FIXED
	;

floating_pt_literal returns [String literal = LT(1).getText()]
	:   f:FLOAT
	;

identifier returns [String id = LT(1).getText()]
	:   IDENT
	;

/* IDL LEXICAL RULES  */
class IDLLexer extends Lexer;
options {
	exportVocab=IDL;
	charVocabulary='\u0000'..'\uFFFE';
	k=4;
}

SEMI
options {
  paraphrase = ";";
}
	:	';'
	;

QUESTION
options {
  paraphrase = "?";
}
	:	'?'
	;

LPAREN
options {
  paraphrase = "(";
}
	:	'('
	;

RPAREN
options {
  paraphrase = ")";
}
	:	')'
	;

LBRACK
options {
  paraphrase = "[";
}
	:	'['
	;

RBRACK
options {
  paraphrase = "]";
}
	:	']'
	;

LCURLY
options {
  paraphrase = "{";
}
	:	'{'
	;

RCURLY
options {
  paraphrase = "}";
}
	:	'}'
	;

OR
options {
  paraphrase = "|";
}
	:	'|'
	;

XOR
options {
  paraphrase = "^";
}
	:	'^'
	;

AND
options {
  paraphrase = "&";
}
	:	'&'
	;

COLON
options {
  paraphrase = ":";
}
	:	':'
	;

COMMA
options {
  paraphrase = ",";
}
	:	','
	;

DOT
options {
  paraphrase = ".";
}
	:	'.'
	;

ASSIGN
options {
  paraphrase = "=";
}
	:	'='
	;

NOT
options {
  paraphrase = "!";
}
	:	'!'
	;

LT
options {
  paraphrase = "<";
}
	:	'<'
	;

LSHIFT
options {
  paraphrase = "<<";
}
	: "<<"
	;

GT
options {
  paraphrase = ">";
}
	:	'>'
	;

RSHIFT
options {
  paraphrase = ">>";
}
	: ">>"
	;

DIV
options {
  paraphrase = "/";
}
	:	'/'
	;

PLUS
options {
  paraphrase = "+";
}
	:	'+'
	;

MINUS
options {
  paraphrase = "-";
}
	:	'-'
	;

TILDE
options {
  paraphrase = "~";
}
	:	'~'
	;

STAR
options {
  paraphrase = "*";
}
	:	'*'
	;

MOD
options {
  paraphrase = "%";
}
	:	'%'
	;


SCOPEOP
options {
  paraphrase = "::";
}
	:  	"::"
	;

WS
options {
  paraphrase = "white space";
}
	:	(' '
	|	'\t'
	|	'\n'  { newline(); }
	|	'\r')
		{ $setType(Token.SKIP); }
	;


PREPROC_DIRECTIVE
options {
  paraphrase = "a preprocessor directive";
}

	:
	'#'!
	(~'\n')* '\n'!
	{ $setType(Token.SKIP); newline(); }
	;


SL_COMMENT
options {
  paraphrase = "a comment";
}

	:
	"//"!
	(~'\n')* '\n'
	{ $setType(Token.SKIP); newline(); }
	;

ML_COMMENT
options {
  paraphrase = "a comment";
}
	:
	"/*"!
	(
			'\n' { newline(); }
		|	('*')+
			(	'\n' { newline(); }
			|	~('*' | '/' | '\n')
			)
		|	~('*' | '\n')
	)*
	"*/"!
	{ $setType(Token.SKIP);  }
	;

CHAR_LITERAL
options {
  paraphrase = "a character literal";
}
	:
	'\''!
	( ESC | ~'\'' )
	'\''!
	;

WIDE_CHAR_LITERAL
options {
  paraphrase = "a wide character literal";
}
	: 'L'! CHAR_LITERAL
	;

STRING_LITERAL
options {
  paraphrase = "a string literal";
}
	:
	'"'!
	(ESC|~'"')*
	'"'!
	;


WIDE_STRING_LITERAL
options {
  paraphrase = "a wide string literal";
}
	:
	'L'! STRING_LITERAL
	;

protected
ESC
options {
  paraphrase = "an escape sequence";
}
	:	'\\'!
		(	'n'		{$setText("\n");}
		|	't'		{$setText("\t");}
		|	'v'		{$setText("\013");}
		|	'b'		{$setText("\b");}
		|	'r'		{$setText("\r");}
		|	'f'		{$setText("\r");}
		|	'a'  		{$setText("\007");}
		|	'\\'		{$setText("\\");}
		|	'?'     	{$setText("?");}
		|	'\''		{$setText("'");}
		|	'"'		{$setText("\"");}
		|	OCTDIGIT
			(options {greedy=true;}:OCTDIGIT
			  (options {greedy=true;}:OCTDIGIT)?
			)?
			{char realc = (char) Integer.valueOf($getText, 8).intValue(); $setText(realc);}
		|       'x'! HEXDIGIT
			(options {greedy=true;}:HEXDIGIT)?
			{char realc = (char) Integer.valueOf($getText, 16).intValue(); $setText(realc);}
		|	'u'!
			HEXDIGIT
			(options {greedy=true;}:HEXDIGIT
			  (options {greedy=true;}:HEXDIGIT
			    (options {greedy=true;}:HEXDIGIT)?
			  )?
			)?
			{char realc = (char) Integer.valueOf($getText, 16).intValue(); $setText(realc);}
		)
	;

protected
VOCAB
options {
  paraphrase = "an escaped character value";
}
	:	'\3'..'\377'
	;

protected
DIGIT
options {
  paraphrase = "a digit";
}
	:	'0'..'9'
	;

protected
NONZERODIGIT
options {
  paraphrase = "a non-zero digit";
}
	:	'1'..'9'
	;

protected
OCTDIGIT
options {
  paraphrase = "an octal digit";
}
	:	'0'..'7'
	;

protected
HEXDIGIT
options {
  paraphrase = "a hexadecimal digit";
}
	:	('0'..'9' | 'a'..'f' | 'A'..'F')
	;

HEX
options {
  paraphrase = "a hexadecimal value value";
}

	:    ("0x" | "0X") (HEXDIGIT)+
	;

INT
options {
  paraphrase = "an integer value";
}
	:    NONZERODIGIT (DIGIT)*                  // base-10
	     (  '.' (DIGIT)*
		 ( (('e' | 'E') ('+' | '-')? (DIGIT)+)	{$setType(FLOAT);}
		 | ('d' | 'D')!				{$setType(FIXED);}
		 |					{$setType(FLOAT);}
		 )
	     |   ('e' | 'E') ('+' | '-')? (DIGIT)+   	{$setType(FLOAT);}
	     |   ('d' | 'D')!				{$setType(FIXED);}
	     )?
	;

OCTAL
options {
  paraphrase = "an octal value";
}
	:    '0'
	     ( (DIGIT)+
	     | FLOAT					{$setType(FLOAT);}
	     | ('d' | 'D')!				{$setType(FIXED);}
	     |						{$setType(INT);}
	     )
	;


FLOAT
options {
  paraphrase = "a floating point value";
}

	:    '.' (DIGIT)+
	     ( ('e' | 'E') ('+' | '-')? (DIGIT)+
	     | ('d' | 'D')!				{$setType(FIXED);}
	     )?
	;

IDENT
options {
  paraphrase = "an identifer";
  testLiterals = true;
}

	:   ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')*
	;

ESCAPED_IDENT
options {
  paraphrase = "an escaped identifer";
  testLiterals = false;			// redundant, but explicit is good.
}
    // NOTE: Adding a ! to the '_' doesn't seem to work,
    //       so we adjust _begin manually.

	:   '_' ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')*
							{_begin++;$setType(IDENT);}
	;


