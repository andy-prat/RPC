/* Generated By:JJTree: Do not edit this line. ASTparam_type.java Version 4.1 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY= */
package com.eprosima.ddscs.idl.ast;

import com.eprosima.ddscs.idl.*;

//@SuppressWarnings("all")
public class ASTparam_type extends SimpleNode {
  public ASTparam_type(int id) {
    super(id);
  }

  public ASTparam_type(IDLParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(IDLParserVisitor visitor, Object data) {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=4b31e7ff323b9abea324c0b4a0535604 (do not edit this line) */
