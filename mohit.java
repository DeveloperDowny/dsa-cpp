static Node insert(char c)
    {
        Node newnode=new Node(c);
        if(m==prefix1.length())
        {
        return newnode;
        }   
        else if (Character.isDigit(c))
        {
            m++;
            return newnode;
        }
        else
        {
            newnode.nextx=insert(prefix1.charAt(++m));
            
            newnode.nexty=insert(prefix1.charAt(m));
            return newnode;
        }
        
 }