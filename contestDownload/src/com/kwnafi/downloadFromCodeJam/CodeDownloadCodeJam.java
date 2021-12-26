package com.kwnafi.downloadFromCodeJam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import com.kwnafi.downloadFromCodeJam.linkExtractionCodeJam;
import com.kwnafi.downloadFromCodeJam.codeJamHttpClient;

public class CodeDownloadCodeJam {
	
	static String codeJamLink = "https://www.go-hero.net/jam/";
	static String codeJamPath = "/home/sr-p2irc-big14/Documents/CodeJamData";
	static String[] languages = {"Java", "C", "Python", "C%23", "C++"};

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		FileReader fr;
		BufferedReader br;
		FileReader fr1;
		BufferedReader br1;
		
		String codeLink;
		String codeSolution;
		String codeDownloadLink;
		String contestSerial;
		String solutionSerial;
		String codeDownload;
		int count = 1;
		linkExtractionCodeJam lk = new linkExtractionCodeJam();
		folderCreation fc = new folderCreation();
		codeJamHttpClient cjHC = new codeJamHttpClient();
		
		for(int i = 8; i<=17; i++ )
		{
			if(i<10)
			{
				codeLink = codeJamLink + '0' + String.valueOf(i) + "/languages/";
			}
			else
			{
				codeLink = codeJamLink +  String.valueOf(i) + "/languages/";
			}
			
			for(int j = 0; j < 5; j++)
			{
				try
				{
					String codeLink1 = codeLink + languages[j];
					System.out.println(codeLink1);
					lk.LinkExtraction(codeLink1);
					
					fr = new FileReader("tempFileCodeJam.txt");
					br = new BufferedReader(fr);
					String tempRead = br.readLine();
					while(tempRead != null)
					{
						codeSolution = tempRead;
						tempRead = br.readLine();
						
						contestSerial = codeLink1.replaceAll("%23", "");
						contestSerial = contestSerial.replaceAll("[^0-9]", "");
						solutionSerial = codeSolution.replaceAll("%23", "");
						solutionSerial = solutionSerial.replaceAll("[^0-9]", "");
						
						//System.out.println("Code Jam: "+ contestSerial);
						//System.out.println("Solution No: "+ solutionSerial);
						
						fc.dirCreation(contestSerial, solutionSerial); // Folder Creation
						
						if(i<10)
						{
							codeDownload = codeJamLink + '0' + String.valueOf(i) + '/'+ codeSolution;
						}
						else
						{
							codeDownload = codeJamLink  + String.valueOf(i) + '/'+ codeSolution;
						}
						
		
						System.out.println("SolutionLink" + codeDownload);
						lk.FileLinkExtraction(codeDownload); /// Code Download Link Generation
						
						fr1 = new FileReader("tempFileCodeJamLink.txt");
						br1 = new BufferedReader(fr1);
						String tempReadLine = br1.readLine();
						while(tempReadLine != null && count < 21)
						{
							codeDownloadLink = tempReadLine;
							tempReadLine = br1.readLine();
							
							cjHC.codeJamLinkDownload(codeDownloadLink, contestSerial, solutionSerial, count);
							count++;
						}
						count = 0;
						
					}
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		}	
	}
}
