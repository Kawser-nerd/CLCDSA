package com.company;

import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import com.opencsv.exceptions.CsvException;

import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class testcsv {
    private static String javaCodeFeatures = "./JavaCodeFeatureFiles.csv";
    private static String csharpCodeFeatures = "./CSharpCodeFeatureFiles.csv";
    private static String pythonCodeFeatures = "./PythonCodeFeatureFiles.csv";
    private static String positiveFileName = "./CrossLanguageClones.csv";
    private static String negativeFileName = "./CrossLanguageNonClones.csv";

    public static void main(String[] args) throws IOException, CsvException {
        String testcsv = "./CSharpCodeFeatureFiles.csv";
        String testoutName = "./CrossLanguageNonClones";
        //csvFilterization(testoutName);
        //csvRowCounter();
        //csvMerge();
        csvModification();

    }
    private static void csvFilterization(String testoutName) throws IOException {
        List<BufferedWriter> writerList = new ArrayList<>();
        BufferedWriter writer1 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "1_final.csv")));
        writerList.add(writer1);
        BufferedWriter writer2 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "2_final.csv")));
        writerList.add(writer2);
        BufferedWriter writer3 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "3_final.csv")));
        writerList.add(writer3);
        BufferedWriter writer4 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "4_final.csv")));
        writerList.add(writer4);
        BufferedWriter writer5 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "5_final.csv")));
        writerList.add(writer5);
        BufferedWriter writer6 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "6_final.csv")));
        writerList.add(writer6);
        BufferedWriter writer7 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "7_final.csv")));
        writerList.add(writer7);
        BufferedWriter writer8 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "8_final.csv")));
        writerList.add(writer8);
        BufferedWriter writer9 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "9_final.csv")));
        writerList.add(writer9);
        BufferedWriter writer10 = new BufferedWriter(new OutputStreamWriter
                (new FileOutputStream(testoutName + "10_final.csv")));
        writerList.add(writer10);

        int noofrows = 1897444 / 47;

        for(int fileNO =0; fileNO < 47; fileNO++) {

            BufferedReader reader = new BufferedReader(new InputStreamReader
                    (new FileInputStream(testoutName +'_'+ fileNO +".csv" )));

            List<String> list = new ArrayList<String>();
            String line = null;

            System.out.println("Data Loading Started "+ fileNO);

            while ((line = reader.readLine()) != null) {
                list.add(line);
            }
            System.out.println("Data Loaded Completely");

            int chunk = 10; // Number of negative output files
            //int noofrows = 1897444; // number of positive rows

            Map<Integer, Integer> numberMap = new HashMap<Integer, Integer>();

            SecureRandom random = new SecureRandom();
            for (int j = 0; j < chunk; j++) {
                System.out.println("Chunk No working "+ j+1);
                for (int i = 0; i < noofrows; i++) {
                    int row = random.nextInt(list.size());
                    if (!numberMap.containsKey(Integer.valueOf(row))) {
                        numberMap.put(Integer.valueOf(row), Integer.valueOf(row));
                        writerList.get(j).write(list.get(row));
                        writerList.get(j).newLine();
                    }
                }
            }
            reader.close();
        }
        writer1.close();
        writer2.close();
        writer3.close();
        writer4.close();
        writer5.close();
        writer6.close();
        writer7.close();
        writer8.close();
        writer9.close();
        writer10.close();
    }

    private static void csvRowCounter() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(positiveFileName)));
        int count = 0;

        while (reader.readLine()!=null)
            count++;

        System.out.println(count);
    }

    private static void csvMerge() throws IOException{
        String BasefileName = "CrossLanguageNonClones";
        String MergingFileName = "CrossLanguageNonClones_47";
        for (int i = 1; i<=10; i++){
            BufferedReader br1 = new BufferedReader(new InputStreamReader(new FileInputStream(BasefileName+i+"_final.csv")));
            BufferedReader br2 = new BufferedReader(new InputStreamReader(new FileInputStream(MergingFileName+i+"_final.csv")));


            List<String> list1 = new ArrayList<String>();

            String line;

            while((line = br1.readLine())!=null){
                list1.add(line);
            }
            while ((line = br2.readLine())!=null)
                list1.add(line);

            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(BasefileName+i+"_final.csv")));

            for(int j =0; j < list1.size(); j++) {
                bw.write(list1.get(j));
                bw.newLine();
            }

            br1.close();
            br2.close();
            bw.close();
        }
    }

    private static void csvModification() throws IOException, CsvException {
        String PositiveClones = "./CrossLanguageClones.csv";
        String NegativeClones = "./CrossLanguageNonClones";

        String OutputPositiveClones = "./PositiveClones.csv";
        String outputNegativeClones = "./NegativeClones";
        /*

        CSVReader csvReader = new CSVReader(new FileReader(PositiveClones));
        CSVWriter csvWriter = new CSVWriter(new FileWriter(OutputPositiveClones));
        String[] temp;

        while ((temp = csvReader.readNext())!=null)
        {
            List<String> list = new ArrayList(Arrays.asList(temp));
            list.add("1");
            String[] arr = new String[list.size()];
            csvWriter.writeNext(list.toArray(arr));
        }
        csvReader.close();
        csvWriter.close();

         */

        for (int i =1; i<=10; i++){
            CSVReader csvReader = new CSVReader(new FileReader(NegativeClones+i+"_final.csv"));
            CSVWriter csvWriter = new CSVWriter(new FileWriter(outputNegativeClones+i+".csv"));

            String[] temp;
            while ((temp = csvReader.readNext()) != null){
                List<String> list = new ArrayList(Arrays.asList(temp));
                list.add("0");
                String[] arr = new String[list.size()];
                csvWriter.writeNext(list.toArray(arr));
            }
            csvReader.close();
            csvWriter.close();
        }
    }

    private static <T, U> List<U> convertStringListToIntList(List<T> listOfString, Function<T, U> function){
        return listOfString.stream().map(function).collect(Collectors.toList());
    }
}
