package mapGenerator;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class mapGen {
	
	public static void main(String args[]) {
		
		File file = new File("map.txt");
		
		try {
			file.createNewFile();
		}catch(IOException e1) {
			e1.printStackTrace();
		}
		
		int[] e_s = new int[9];
		worm(e_s);
		
		Random rdm = new Random();
		
		for(int r = 0; r < 9; r++) 
				System.out.println(e_s[r]);
		try {
			FileWriter fw = new FileWriter(file);
			for(int r = 0; r < 9; r++)
			{
				for(int c = 0; c < 9; c++) {
					if(r == 0 && e_s[0] == c) fw.append('E');
					else if (r == 8 && e_s[8] == c) fw.append('S');
					else if(((r==0 || c==0 || r==8 || c==8) || (rdm.nextInt(2)==0)) && c != e_s[r]) fw.append('*');
					else fw.append(' ');
				}
				if(r!=8)fw.append('\n');
			}
			fw.close();
		} catch (IOException e1) {
			
			e1.printStackTrace();
		}
	}
	
	public static void worm(int[] e_s) {
	
		Random rdm = new Random();
		int prev = rdm.nextInt(7)+1;
		for (int i = 0; i<9; i++) {
			if (prev==0)prev += rdm.nextInt(2);
			else if (prev==8)prev -= rdm.nextInt(2);
			else if(rdm.nextInt(2) == 0) ++prev;
			else --prev;
			
			e_s[i] = prev;
		}
	}
}

