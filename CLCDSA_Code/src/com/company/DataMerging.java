package com.company;

import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import com.opencsv.exceptions.CsvValidationException;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;

public class DataMerging {
    private static String positiveFileName = "./CrossLanguageClones.csv";
    private static String negativeFileName = "./CrossLanguageNonClones.csv";
    private static String javaCodeFeatures = "./JavaCodeFeatureFiles.csv";
    private static String csharpCodeFeatures = "./CSharpCodeFeatureFiles.csv";
    private static String pythonCodeFeatures = "./PythonCodeFeatureFiles.csv";

    public static void main(String[] args) throws IOException, CsvValidationException {

         String[][] comparisonPreferences = new String[6][2];
         comparisonPreferences[0][0] = javaCodeFeatures;
         comparisonPreferences[0][1] = csharpCodeFeatures;
         comparisonPreferences[1][0] = javaCodeFeatures;
         comparisonPreferences[1][1] = pythonCodeFeatures;
         comparisonPreferences[2][0] = csharpCodeFeatures;
         comparisonPreferences[2][1] = pythonCodeFeatures;
         comparisonPreferences[3][0] = csharpCodeFeatures;
         comparisonPreferences[3][1] = javaCodeFeatures;
         comparisonPreferences[4][0] = pythonCodeFeatures;
         comparisonPreferences[4][1] = javaCodeFeatures;
         comparisonPreferences[5][0] = pythonCodeFeatures;
         comparisonPreferences[5][1] = csharpCodeFeatures;

         CSVWriter cloneWriter = new CSVWriter(new FileWriter(positiveFileName));
         //CSVWriter nonCloneWriter = new CSVWriter(new FileWriter(negativeFileName));

         for(int i = 0; i < comparisonPreferences.length; i++)
             dataCreation(comparisonPreferences[i][0], comparisonPreferences[i][1], cloneWriter);
             //dataCreation(comparisonPreferences[i][0], comparisonPreferences[i][1], cloneWriter, nonCloneWriter);

         cloneWriter.close();
         //nonCloneWriter.close();
    }

    //private static void dataCreation(String source, String target, CSVWriter cloneWriter,
    //                                 CSVWriter nonCloneWriter) throws IOException, CsvValidationException {
    private static void dataCreation(String source, String target, CSVWriter cloneWriter)
            throws IOException, CsvValidationException {
        CSVReader sourceReader = new CSVReader(new FileReader(source));

        String[] sourceRecord;
        String[] targetRecord;
        String[] temp = new String[18];

        while ((sourceRecord = sourceReader.readNext())!= null){
            CSVReader targetReader = new CSVReader(new FileReader(target));
            while ((targetRecord = targetReader.readNext())!= null){
                /// Merging the arrays ///
                for(int i = 1; i < sourceRecord.length; i++)
                   temp [(i - 1)] = sourceRecord[i];
                for (int i = 1; i < targetRecord.length; i++)
                   temp [i+8] = targetRecord[i];
                //// Clones and Nonclones writing

                if (sourceRecord[0].equals(targetRecord[0]))
                    cloneWriter.writeNext(temp);
                /*
                else
                    nonCloneWriter.writeNext(temp);

                 */

            }
        }

    }
}
