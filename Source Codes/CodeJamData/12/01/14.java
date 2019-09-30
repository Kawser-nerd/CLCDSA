import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collection.*;

public class A
{
    static char[] Cipher = new char[256];
    public static void train()
    {
        String in  = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyeq",
               out = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupaoz";
        fill(Cipher, (char)0);
        for(int i = 0; i < in.length(); ++i)
            Cipher[in.charAt(i)] = out.charAt(i);
        for(char i = 'a'; i <= 'z'; ++i)
        {
            if(Cipher[i] == 0)
            {
                char j, k;
                for(j = 'a'; j <= 'z'; ++j)
                {
                    for(k = 'a'; k <= 'z'; ++k)
                        if(Cipher[k] == j)
                            break;
                    if(k > 'z')
                        break;
                }
                Cipher[i] = j;
            }
        }
        for(int i = 'a'; i <= 'z'; ++i)
            if(Cipher[i] != 0)
                Cipher[i - 'a' + 'A'] = (char)(i + ('A' - 'a'));
    }
    public static void main(String[] args) throws IOException
    {
        train();
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for(int t = 0; t++ < T; )
        {
            out.print("Case #" + t +": "); 
            for(char c : br.readLine().toCharArray())
                out.print(Cipher[c] == 0 ? c : Cipher[c]);
            out.println();
        }
    }
}
