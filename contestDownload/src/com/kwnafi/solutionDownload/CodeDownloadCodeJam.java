package com.kwnafi.solutionDownload;

import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class CodeDownloadCodeJam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Document doc = null;
		
		try {
			doc = Jsoup.connect("https://www.go-hero.net/jam/08/solutions/0/1/C++").get();
			
			String title = doc.title();
			System.out.println("title: " + title);
			
			Elements links = doc.select("a[href]");
			
			
			for (Element link : links) {
				String str = link.attr("href");
				int i =str.indexOf("/");
				if(i != -1)
				{
					if(str.substring(0, i).equals("http:"))
						{
							System.out.println("\nLink : " + link.attr("href"));
							
						}
				}
			}
		
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}

}
