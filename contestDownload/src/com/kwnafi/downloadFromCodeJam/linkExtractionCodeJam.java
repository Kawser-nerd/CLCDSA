package com.kwnafi.downloadFromCodeJam;

import java.io.FileWriter;
import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class linkExtractionCodeJam {
	
	public void LinkExtraction(String codeLink)
	{
		Document doc = null;
		
		try {
			doc = Jsoup.connect(codeLink).get();
			
			//String title = doc.title();
			//System.out.println("title: " + title);
			
			FileWriter fw = new FileWriter("tempFileCodeJam.txt");
			
			Elements links = doc.select("a[href]");
			
			
			for (Element link : links) {
				
				String str = link.attr("href");
				int i =str.indexOf("/");
				if(i != -1)
				{
					if(str.substring(0, i).equals("solutions"))
						{
							System.out.println("\nLink : " + link.attr("href"));
							fw.write(link.attr("href"));
							fw.write("\n");
						}
				}
				
			}
			System.out.println("File Created Successfully");
			fw.close();
		
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void FileLinkExtraction(String codeLink)
	{
		Document doc = null;
		
		try {
			doc = Jsoup.connect(codeLink).get();
			
			//String title = doc.title();
			//System.out.println("title: " + title);
			
			FileWriter fw = new FileWriter("tempFileCodeJamLink.txt");
			
			Elements links = doc.select("a[href]");
			
			
			for (Element link : links) {
				
				String str = link.attr("href");
				int i =str.indexOf("/");
				if(i != -1)
				{
					if(str.substring(0, i).equals("http:"))
						{
							System.out.println("\nLink : " + link.attr("href"));
							fw.write(link.attr("href"));
							fw.write("\n");
						}
				}
				
			}
			System.out.println("File Created Successfully");
			fw.close();
		
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
