package com.kwnafi.downloadFromCodeJam;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.HttpClientBuilder;

public class codeJamHttpClient {
	
	static String tempZip = "/home/sr-p2irc-big14/Dropbox/Phd_Paper_2/contestDownload/tempFolder/test.zip";
	static String CodeBaseMain = "/home/sr-p2irc-big14/Documents/CodeJamData/"; 
	
	public void codeJamLinkDownload(String codejamlink, String contestSerial, String solutionSerial, int count)
	{
		HttpClient client = HttpClientBuilder.create().build();
		
		HttpGet request = new HttpGet(codejamlink);
		
		try {
			HttpResponse response = client.execute(request);
			
			HttpEntity entity = response.getEntity();
			
			if(entity != null)
			{
				FileOutputStream fos = new FileOutputStream(tempZip.toString());
				entity.writeTo(fos);
				fos.close();
				Unzipfile(contestSerial, solutionSerial, count);
				
			}
			
		} catch (ClientProtocolException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void Unzipfile(String contestSerial, String solutionSerial, int count) throws IOException
	{
		String CodeBase = CodeBaseMain + contestSerial + '/' + solutionSerial;
		File destDir = new File(CodeBase.toString());
        byte[] buffer = new byte[1024];
        ZipInputStream zis;
		try {
			zis = new ZipInputStream(new FileInputStream(tempZip.toString()));
			ZipEntry zipEntry = zis.getNextEntry();
	        while (zipEntry != null) {
	            File newFile = newFile(destDir, zipEntry, count);
	            FileOutputStream fos = new FileOutputStream(newFile);
	            int len;
	            while ((len = zis.read(buffer)) > 0) {
	                fos.write(buffer, 0, len);
	            }
	            fos.close();
	            zipEntry = zis.getNextEntry();
	        }
	        zis.closeEntry();
	        zis.close();
	        
	        
	        
	        
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
	}
	
	public static File newFile(File destinationDir, ZipEntry zipEntry, int count) throws IOException, ArrayIndexOutOfBoundsException {
		
		
		String zipfilename = zipEntry.getName();
		
		if(zipfilename.contains("."))
		{
		String FileName = String.valueOf(count) +"."+ zipfilename.split("\\.")[1];
		
		System.out.println(FileName);
		
        File destFile = new File(destinationDir, FileName);
         
        String destDirPath = destinationDir.getCanonicalPath();
        String destFilePath = destFile.getCanonicalPath();
         
        if (!destFilePath.startsWith(destDirPath + File.separator)) {
            throw new IOException("Entry is outside of the target dir: " + zipEntry.getName());
        }
        
         
        return destFile;
		}
		else
		{
			File destFile = new File(destinationDir, "file.txt");
			return destFile;
		}
	}
    
}
