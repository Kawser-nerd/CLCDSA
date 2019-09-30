using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading.Tasks;


class maki {
    static void Main(string[] args) {
        //int[] b=Console.ReadLine().Split().Select(int.Parse).ToArray();
        string s=Console.ReadLine();
        bool ans=true;
        int n=s.Length;
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]){
                ans=false;
            }
        }
        if(ans==true){
            Console.WriteLine("YES");
        }
        else{
            Console.WriteLine("NO");
        }

    }
}