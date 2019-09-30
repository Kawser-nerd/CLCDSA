package world2014.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MinesweeperMaster {

	public String solve(int R, int C, int M) {
		if (R<C) {
			String res = this.solve(C, R, M);
			if (res.equals("Impossible"))
				return res;
			StringBuilder sb = new StringBuilder();
			for (int i=0; i<R; i++)
				for (int j=0; j<C; j++)
					sb.append(res.charAt(j*R+i));
			return sb.toString();
		}
		int mm = R*C-M;
		if (mm==1 || C==1)
			return this.createBoard(mm, M);
		if (mm==2 || mm==3 || mm==5 || mm==7)
			return "Impossible";
		if (C==2) {
			if (mm%2==1)
				return "Impossible";
			return this.createBoard(mm, M);
		}
		if (mm<C*2) {
			if (mm%2==0) {
				StringBuilder sb = new StringBuilder();
				sb.append("c");
				for (int i=1; i<mm/2; i++)
					sb.append(".");
				for (int i=mm/2; i<C; i++)
					sb.append("*");
				for (int i=0; i<mm/2; i++)
					sb.append(".");
				for (int i=mm/2; i<C; i++)
					sb.append("*");
				for (int i=0; i<(R-2)*C; i++)
					sb.append("*");
				return sb.toString();
			} else {
				StringBuilder sb = new StringBuilder();
				sb.append("c");
				for (int i=1; i<mm/2-1; i++)
					sb.append(".");
				for (int i=mm/2-1; i<C; i++)
					sb.append("*");
				for (int i=0; i<mm/2-1; i++)
					sb.append(".");
				for (int i=mm/2-1; i<C; i++)
					sb.append("*");
				for (int i=0; i<3; i++)
					sb.append(".");
				for (int i=0; i<(R-2)*C-3; i++)
					sb.append("*");
				return sb.toString();
			}
		} else if (mm%C!=1) {
			return this.createBoard(mm, M);
		} else if (mm>=C*3) {
			StringBuilder sb = new StringBuilder();
			sb.append("c");
			for (int i=0; i<(mm/C)*C-2; i++)
				sb.append(".");
			sb.append("*");
			for (int i=0; i<(mm%C)+1; i++)
				sb.append(".");
			for (int i=0; i<M-1; i++)
				sb.append("*");
			return sb.toString();
		} else {
			StringBuilder sb = new StringBuilder();
			sb.append("c");
			for (int i=1; i<C-1; i++)
				sb.append(".");
			sb.append("*");
			for (int i=0; i<C-1; i++)
				sb.append(".");
			sb.append("*");
			for (int i=0; i<(mm%C)+2; i++)
				sb.append(".");
			for (int i=0; i<M-1; i++)
				sb.append("*");
			return sb.toString();
		}
	}
	
	private String createBoard(int mm, int M) {
		StringBuilder sb = new StringBuilder();
		sb.append("c");
		for (int i=0; i<mm-1; i++)
			sb.append(".");
		for (int i=0; i<M; i++)
			sb.append("*");
		return sb.toString();
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2014/qualification_round/C-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int problemNum = Integer.parseInt(line);
		for (int i=0; i<problemNum; i++) {
			line = br.readLine();
			String[] splitted = line.split(" ");
			int R = Integer.parseInt(splitted[0]);
			int C = Integer.parseInt(splitted[1]);
			int M = Integer.parseInt(splitted[2]);
			String res = new MinesweeperMaster().solve(R, C, M);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ":");
			System.out.println(sb);
			pw.println(sb);
			if (res.equals("Impossible")) {
				System.out.println(res);
				pw.println(res);
			} else
				for (int r=0; r<R; r++) {
					String s = res.substring(r*C, (r+1)*C);
					System.out.println(s);
					pw.println(s);
				}
		}
		br.close();
		pw.close();
	}
}
