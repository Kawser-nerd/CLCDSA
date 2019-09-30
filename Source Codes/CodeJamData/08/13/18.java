import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.math.MathContext;

public class C {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c.in")));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("c.out")));
        int n = Integer.parseInt(reader.readLine().trim());
        for(int id = 1; id <= n; id++){
            int st = Integer.parseInt(reader.readLine().trim());
            BigDecimal d3 = new BigDecimal(3);
            BigDecimal d5 = new BigDecimal("2.23606797749978969640917366873127623544061835961152572427089");
            BigDecimal sum = d3.add(d5);
            BigDecimal pow = sum.pow(st);
            String res = "000"+pow.toString();
            res = res.substring(res.indexOf('.')-3,res.indexOf('.'));
            writer.write(String.format("Case #%d: %s%n", id, res));
        }
        writer.close();
    }
}