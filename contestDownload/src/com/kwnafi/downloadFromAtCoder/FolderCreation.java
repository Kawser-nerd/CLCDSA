package com.kwnafi.downloadFromAtCoder;

import java.io.File;

public class FolderCreation {
	
	static String codeFolder = "C:\\Users\\kwnaf\\OneDrive\\Documents\\AtCoder";
	
	public String dirCreation(String contestSerial, String questionName)
	{
		String newFolder = codeFolder + '\\' +contestSerial;
		File theContest = new File(newFolder.toString());
		
		newFolder = codeFolder + '\\' +contestSerial + '\\' + questionName;
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
