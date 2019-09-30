using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC113_C{
    struct P{
        public int city;
        public int year;
        public int id;
        public int number;
        public P(int city,int year,int id){
            this.city = city;
            this.year = year;
            this.id = id;
            this.number = 1;

        }
    }
    class Program{
        static void Main(string[] args){
            var line = Console.ReadLine().Split(' ');
            var N = int.Parse(line[0]);
            var M = int.Parse(line[1]);
            var list = new List<P>();

            for(var i = 0;i < M;i++){
                var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                list.Add(new P(input[0],input[1],i));
            }
            
            var list2 = list.OrderBy(x => x.city).ThenBy(x => x.year).ToArray();
            
            var temp = list2[0].city;
            var numTemp = 1;
            list2[0].number = numTemp;

            for(var i = 1;i < M;i++){
                if(temp == list2[i].city){
                    list2[i].number = ++numTemp;
                }else{
                    numTemp = 1;
                    list2[i].number = numTemp;
                    temp = list2[i].city;
                    
                }
            }

            foreach(var i in list2.OrderBy(x => x.id)){
                Console.WriteLine($"{i.city:D6}{i.number:D6}");
            }




        }
    }
}