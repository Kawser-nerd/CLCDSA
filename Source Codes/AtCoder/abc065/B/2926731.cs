using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static void Main()
	{
        int n = int.Parse(Console.ReadLine());
        int[] button = new int[n+1];

        for(int i = 0 ; i < n ; i++){
            button[i] = int.Parse(Console.ReadLine());
        }

        int ans = 0;
        bool can = false;
        
        int currentButton = 0;
        while(n > 0){
            if(currentButton == 1){
                can = true;
                break;
            } else {
                currentButton = button[currentButton] -1;
            }
            n--;
            ans++;
        }

        if(can){
            Console.WriteLine(ans);
        } else {
            Console.WriteLine("-1");
        }
    }                                                                                                                                                                       
}