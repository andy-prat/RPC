/* Generated By:JJTree: Do not edit this line. ASTstring.java Version 4.1 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY= */
package com.eprosima.ddscs.idl.ast;

import com.eprosima.ddscs.idl.*;

//@SuppressWarnings("all")
public class ASTstring extends SimpleNode {
  public ASTstring(int id) {
    super(id);
  }

  public ASTstring(IDLParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(IDLParserVisitor visitor, Object data) {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=d6ae613770e11b546ddb13ee3413ed1e (do not edit this line) */
