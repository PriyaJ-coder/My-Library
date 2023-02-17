import java.util.*;   
// import java.io.*;   

class sort{
	static void sortedInsert(Stack<Integer> s, int x)
    {
        if (s.isEmpty() || x > s.peek()) {
            s.push(x);
            return;
        }
        int temp = s.pop();
        sortedInsert(s, x);
        s.push(temp);
    }
    
	static Stack<Integer> sortStack(Stack<Integer> s)
	{
        if (!s.isEmpty()) {
            int x = s.pop();
            sortStack(s);
            sortedInsert(s, x);
        }
        return s;
	}

    public static void main(String[] args)
    {
        Stack<Integer> s = new Stack<>();
        s.push(90);
        s.push(-5);
        s.push(18);
        s.push(14);
        s.push(-3);
 
        s=sortStack(s);

        System.out.println(s);
 
    }
}