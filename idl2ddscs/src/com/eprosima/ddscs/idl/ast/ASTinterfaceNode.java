/* Generated By:JJTree: Do not edit this line. ASTinterfaceNode.java Version 4.1 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY= */
package com.eprosima.ddscs.idl.ast;

import com.eprosima.ddscs.idl.*;

//@SuppressWarnings("all")
public class ASTinterfaceNode extends SimpleNode {
  public ASTinterfaceNode(int id) {
    super(id);
  }

  public ASTinterfaceNode(IDLParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(IDLParserVisitor visitor, Object data) {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=01ff5738d750428ce27fd2c0803119b7 (do not edit this line) */
