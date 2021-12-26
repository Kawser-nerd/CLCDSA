package com.company;

import java.io.*;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class testcsv {
    private static String javaCodeFeatures = "./JavaCodeFeatureFiles.csv";
    private static String csharpCodeFeatures = "./CSharpCodeFeatureFiles.csv";
    private static String pythonCodeFeatures = "./PythonCodeFeatureFiles.csv";
    private static String positiveFileName = "./CrossLanguageClones.csv";
    private static String negativeFileName = "./CrossLanguageNonClones.csv";

    public static void main(String[] args) throws IOException{
        String testcsv = "./CSharpCodeFeatureFiles.csv";
        String testoutName = "./test.csv";
        csvFilterization(testcsv);
        //csvRowCounter();

    }
    private static void csvFilterization(String testcsv) throws IOException {


        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(testcsv)));

        List<String> list = new ArrayList<String>();
        String line = null;

        while((line = reader.readLine())!= null){
            list.add(line);
        }

        int chunk = 3; // Number of negative output files
        //int noofrows = 1897444; // number of positive rows
        int noofrows = 100;
        Map<Integer, Integer> numberMap = new HashMap<Integer, Integer>();

        SecureRandom random = new SecureRandom();
        for (int j = 0; j< chunk; j++){
            String fileName = "./test_" + String.valueOf(j+1) + ".csv";
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
            }
            writer.close();
        }
        reader.close();

    }

    private static void csvRowCounter() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(positiveFileName)));
        int count = 0;

        while (reader.readLine()!=null)
            count++;

        System.out.println(count);
    }
}
