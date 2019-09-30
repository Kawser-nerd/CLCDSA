using System;
using System.Linq;
using System.Collections.Generic;

namespace City
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var list = new List<string>();
            while (true)
            {
                string line = Console.ReadLine();
                if (line == null) break;
                list.Add(line);
            }
            //list.RemoveAt(0);

           // List<string> list = new List<string>();
            List<string> CityList = new List<string>();
            List<string> CityNumber = new List<string>();
            //list.Add("4");
            //list.Add("unagi 20");
            //list.Add("usagi 13");

            //list.Add("smeke 7");
            //list.Add("snuke 22");
            list.RemoveAt(0);


            foreach (var item in list)
            {
                    int cityCount = 0;
                    string[] cityName = item.Split(' ');
                    CityList.Add(cityName[cityCount]);
                    cityCount++;
                    CityNumber.Add(cityName[cityCount]);                    
            }

            double cityNo = 0;
            double cityNoTotal = 0;
            foreach (var item in CityNumber)
            {
                cityNo = double.Parse(item);
                cityNoTotal= cityNoTotal + cityNo;
            }

            double hfNo = cityNoTotal / 2;
            int count = 0;
            

            foreach (var item in CityNumber)
            {
                if (hfNo<int.Parse(item))
                {
                    string ans = CityList[count];
                    Console.WriteLine(ans);
                }
                else
                {
                    if (count.Equals(list.Count-1))
                    {
                        Console.WriteLine("atcoder");
                    }
                    else
                    {
                        count++;
                    }
                }                
            }

        }
    }
}