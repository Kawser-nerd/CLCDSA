using System;
         
        class Program{
        	static void Main(string[] args){
            	string[] input = Console.ReadLine().Split(' ');
              	int[] count = new int[10];
              	for(int i = 0;i < input.Length;i ++){
                	int check = int.Parse(input[i]);
                  	count[check - 1] ++;
                }
              
              	if(count[4] == 2 && count[6] == 1){
                	Console.WriteLine("YES");
                }else Console.WriteLine("NO");
            }
        }