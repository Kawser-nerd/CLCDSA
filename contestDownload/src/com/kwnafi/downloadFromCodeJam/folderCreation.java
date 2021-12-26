package com.kwnafi.downloadFromCodeJam;

import java.io.File;

public class folderCreation {
	
static String codeFolder = "/home/sr-p2irc-big14/Documents/CodeJamData";
	
	public String dirCreation(String contestSerial, String questionName)
	{
		String newFolder = codeFolder + '/' +contestSerial;
		File theContest = new File(newFolder.toString());
		
		newFolder = codeFolder + '/' +contestSerial + '/' + questionName;
		File theQues = new File(newFolder.toString());
		

		// if the directory does not exist, create it
		if (!theContest.exists()) {
		    System.out.println("creating directory: " + theContest.getName());
		    boolean result = false;

		    try{
		        theContest.mkdir();
		        result = true;
		    } 
		    catch(SecurityException se){
		        se.printStackTrace();
		    }        
		    if(result) {    
		        System.out.println("DIR created");
		    }
		    else
		    {
		    	System.out.println("DIR created");
		    	System.exit(0);	
		    }
		}
		
		if(!theQues.exists()) {
			System.out.println("creating directory: " + theQues.getName());
		    boolean result = false;

		    try{
		        theQues.mkdir();
		        result = true;
		    } 
		    catch(SecurityException se){
		        se.printStackTrace();
		    }        
		    if(result) {    
		        System.out.println("DIR created");
		    }
		    else
		    {
		    	System.out.println("DIR created");
		    	System.exit(0);
		    }
			
		}
		
		return theQues.getPath().toString();
	}

}
