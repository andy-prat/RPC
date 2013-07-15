package com.eprosima.rpcdds.typecode;

import org.antlr.stringtemplate.StringTemplate;

import com.eprosima.rpcdds.util.Pair;

public class AliasTypeCode extends ContainerTypeCode
{
    public AliasTypeCode(String scope, String name)
    {
        super(TypeCode.KIND_ALIAS);
        m_scope = scope;
        m_name = name;
    }
    
    public String getScopedname()
    {
        return m_scope + m_name;
    }

    @Override
    public String getTypename()
    {
    	StringTemplate st = getTypenameFromStringTemplate();
        st.setAttribute("name", getScopedname());
        return st.toString();
    }
    
    @Override
    public String getStTypename()
    {
    	StringTemplate st = getSTTypenameFromStringTemplate();
        st.setAttribute("name", getScopedname());
        return st.toString();
    }
    
    @Override
    public String getInitialValue()
    {   
        return "0";
    }
    
    public Pair<Integer, Integer> getMaxSerializedSize(int currentSize, int lastDataAligned)
    {
        // TODO
    	return null;
    }
    
    public int getMaxSerializedSizeWithoutAlignment(int currentSize)
    {
    	// TODO
        return 0;
    }
    
    private String m_name = null;
    
    private String m_scope = null;
}