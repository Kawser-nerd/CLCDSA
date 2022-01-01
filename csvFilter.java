import java.io.*;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class csvFilter {
    private static String negativeFileName = "./CrossLanguageNonClones.csv";

    public static void main(String[] args) throws IOException{
        String testcsv = negativeFileName;
		csvFilterization(testcsv);
        //csvRowCounter();

    }
    private static void csvFilterization(String testcsv) throws IOException {


        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(testcsv)));

        List<String> list = new ArrayList<String>();
        String line = null;

        int count = 0;
        System.out.println("Data Loading Started");

        while((line = reader.readLine())!= null){
            count++;
			list.add(line);
            if(count%100000 == 0)
                System.out.println("Number of loaded Lines "+ count);
        }
        System.out.println("Data Loaded Completely");

        int chunk = 10; // Number of negative output files
        int noofrows = 1897444; // number of positive rows
        Map<Integer, Integer> numberMap = new HashMap<Integer, Integer>();

        System.out.println("Data Chunking Started");

        SecureRandom random = new SecureRandom();
        for (int j = 0; j< chunk; j++){
            count = 0;
            String fileName = "./CrossLanguageNonClones_" + String.valueOf(j+1) + ".csv";
            System.out.println("Started Chunk no "+ String.valueOf(j + 1));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(fileName)));
            for(int i = 0; i < noofrows; i++ )
            {
                int row = random.nextInt(list.size());
                if(!numberMap.containsKey(Integer.valueOf(row)))
                {
                    numberMap.put(Integer.valueOf(row), Integer.valueOf(row));
                    writer.write(list.get(row));
                    writer.newLine();
                }
                count++;
                if(count%100000 == 0)
                    System.out.println("Number of written Lines "+ count);
            }
            writer.close();
        }
        reader.close();
    }
}
