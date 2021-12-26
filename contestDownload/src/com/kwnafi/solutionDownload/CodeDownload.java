package com.kwnafi.solutionDownload;

import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class CodeDownload {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Document doc = null;
		
		//// Download ATPGrad Contest
		
		
		try {
			doc = Jsoup.connect("https://atcoder.jp/contests/agc001/submissions?f.Task=agc001_a&f.Language=3016&f.Status=AC&f.User=").get();
			
			String title = doc.title();
			System.out.println("title: " + title);
			
			//System.out.println(doc.toString());
			
			
			Elements links = doc.select("a");
			
			
			for (Element link : links) {
				String test = link.text().toString();
				if(test.equals("Detail"))
				{
					System.out.println("\nLink : " + link.attr("href"));
					System.out.println("Text : " + link.text());
				}
			}
		
		//	String link = doc.body().getElementsByTag("pre").text();
		//	System.out.println(link);
		
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}

}
