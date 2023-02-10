// import java.util.*;   
// import java.io.*;   
import java.util.Scanner;  
  
class LCS {  
      
    public static int findLengthOfLCS(String str1, String str2, int p, int q) {  
      
        int[][] LCS = new int[p + 1][q + 1];  
  
        for (int i = 0; i <= p; i++) {  
            for (int j = 0; j <= q; j++) {  
                if (i == 0 || j == 0)  
                    LCS[i][j] = 0;  // Fill each cell corresponding to first row and first column with 0  
                else if (str1.charAt(i - 1) == str2.charAt(j - 1))  
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;  
                else  
                    LCS[i][j] = Math.max(LCS[i - 1][j], LCS[i][j - 1]);
            }  
        }  
      
        int index = LCS[p][q];  

        return index;  
    }  
    public static void main(String[] args) {  
          
        String str1, str2;  
          
        Scanner sc= new Scanner(System.in); //System.in is a standard input stream.  
        System.out.print("Enter 1st sequence: ");  
        str1 = sc.nextLine(); //reads string.  
          
        System.out.print("Enter 2nd sequence: ");  
        str2 = sc.nextLine(); //reads string.  

        sc.close();
          
        int p = str1.length();  
        int q = str2.length();  
          
        int LCS = findLengthOfLCS(str1, str2, p, q);  

        System.out.println("The longest possible common sequence is of length " + LCS);
        
    }  
}  