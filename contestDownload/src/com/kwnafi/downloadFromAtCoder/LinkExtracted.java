package com.kwnafi.downloadFromAtCoder;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class LinkExtracted {
	static String codeLink = "https://atcoder.jp";
	static String codePath = "C:\\Users\\kwnaf\\OneDrive\\Documents\\AtCoder";
	
	public void LinkExtraction(String linkDownload)
	{
		Document doc = null;
	
		try {
			doc = Jsoup.connect(linkDownload).get();
		
			
			FileWriter fw = new FileWriter("tempLink.txt");
		
			Elements links = doc.select("a");
		
		
			for (Element link : links) {
				String test = link.text().toString();
				if(test.equals("Detail"))
				{
					//System.out.println("Link : " + link.attr("href"));
					//Links[count] = link.attr("href");
					fw.write(link.attr("href"));
					fw.write("\n");
					//wr.append("\n");
					
				}
			}
			fw.close();
			
			
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
		}

	}
	
	public void CodeDownLoad(String contestSerial, String question, String extension) 
	{
		FileReader fr;
		BufferedReader br;
		FileWriter fw;
		Document doc;
		try {
			fr = new FileReader("tempLink.txt");
			br = new BufferedReader(fr);
			String tempRead = br.readLine(); 
		    while (tempRead != null) {
		    	System.out.println(tempRead);
		    	
		    	String CodeLink = codeLink + tempRead;
		    	System.out.println(CodeLink);
		    	tempRead = br.readLine();
		    	
		    	String fileName = CodeLink.substring(CodeLink.length() - 7) + extension;
		    	System.out.println(fileName);
		    	String filePath = codePath + "\\"+ contestSerial + "\\" + question + "\\" + fileName;
		    	
		    	fw = new FileWriter(filePath);
		    	
		    	doc = Jsoup.connect(CodeLink).get();
		    	String codeBlock = doc.body().getElementsByTag("pre").text();
		    	
		    	fw.write(codeBlock);
		    	System.out.println("Successfully Writted");
		    	fw.close();
		    }
		     
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
			  
			    
	}
	
}
