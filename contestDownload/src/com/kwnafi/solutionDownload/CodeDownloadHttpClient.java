package com.kwnafi.solutionDownload;

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

public class CodeDownloadHttpClient {
	
	static String tempZip = "/home/sr-p2irc-big14/Dropbox/Phd_Paper_2/contestDownload/tempFolder/test.zip";
	static String CodeBase = "/home/sr-p2irc-big14/Dropbox/Phd_Paper_2/contestDownload/codes"; 

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		HttpClient client = HttpClientBuilder.create().build();
		
		HttpGet request = new HttpGet("http://code.google.com/codejam/contest/scoreboard/do?cmd=GetSourceCode&contest=433101&problem=502103&io_set_id=1&username=madking");
		
		try {
			HttpResponse response = client.execute(request);
			
			HttpEntity entity = response.getEntity();
			
			if(entity != null)
			{
				FileOutputStream fos = new FileOutputStream(tempZip.toString());
				entity.writeTo(fos);
				fos.close();
				Unzipfile();
				
			}
			
		} catch (ClientProtocolException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void Unzipfile() throws IOException
	{
		File destDir = new File(CodeBase.toString());
        byte[] buffer = new byte[1024];
        ZipInputStream zis;
		try {
			zis = new ZipInputStream(new FileInputStream(tempZip.toString()));
			ZipEntry zipEntry = zis.getNextEntry();
	        while (zipEntry != null) {
	            File newFile = newFile(destDir, zipEntry);
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
	
	public static File newFile(File destinationDir, ZipEntry zipEntry) throws IOException {
        File destFile = new File(destinationDir, zipEntry.getName());
         
        String destDirPath = destinationDir.getCanonicalPath();
        String destFilePath = destFile.getCanonicalPath();
         
        if (!destFilePath.startsWith(destDirPath + File.separator)) {
            throw new IOException("Entry is outside of the target dir: " + zipEntry.getName());
        }
         
        return destFile;
    }
	

}
