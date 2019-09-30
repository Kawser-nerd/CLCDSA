import java.io.*;

public class B {
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cases, combine_count, oppose_count, invoke_count;
        String[] input, combine, oppose;
        String invoke;
        StringBuilder result;
        
        cases = Integer.parseInt(in.readLine());
        for (int c=1; c<=cases; c++) {
            input = in.readLine().split(" ");
            combine_count = Integer.parseInt(input[0]);
            combine = new String[combine_count];
            for (int i=0; i<combine_count; i++)
                combine[i] = input[i+1];
            oppose_count = Integer.parseInt(input[combine_count+1]);
            oppose = new String[oppose_count];
            for (int i=0; i<oppose_count; i++)
                oppose[i] = input[i+combine_count+2];
            invoke_count = Integer.parseInt(input[combine_count+oppose_count+2]);
            invoke = input[combine_count+oppose_count+3];
            
            result = new StringBuilder();
invokeloop:
            for (int i=0; i<invoke_count; i++) {
                char invoked = invoke.charAt(i);
                if (result.length() == 0) {
                    result.append(invoked);
                } else {
                    char last = result.charAt(result.length() - 1);
                    for (String combination : combine)
                    {
                        if (combination.charAt(0) == invoked && combination.charAt(1) == last || combination.charAt(0) == last && combination.charAt(1) == invoked)
                        {
                            result.setCharAt(result.length() - 1, combination.charAt(2));
                            continue invokeloop;
                        }
                    }
                    for (int j=0; j<result.length(); j++)
                    {
                        char earlier = result.charAt(j);
                        for (String opposition : oppose)
                        {
                            if (opposition.charAt(0) == invoked && opposition.charAt(1) == earlier || opposition.charAt(0) == earlier && opposition.charAt(1) == invoked)
                            {
                                result.delete(0, result.length());
                                continue invokeloop;
                            }
                        }
                    }
                    result.append(invoked);
                }
            }
            
            System.out.print("Case #" + c + ": [");
            for (int i=0; i<result.length(); i++)
            {
                if (i != 0)
                    System.out.print(", ");
                System.out.print(result.charAt(i));
            }
            System.out.println("]");
        }
    }
    
}
