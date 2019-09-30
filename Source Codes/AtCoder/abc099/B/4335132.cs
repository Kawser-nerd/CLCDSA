using System;
using System.Collections.Generic;
using System.Linq;


namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            int a,b;
            {
                var tmp = Console.ReadLine().Split(' ')
                .Select(i=>int.Parse(i)).ToArray();
                a = tmp[0];
                b = tmp[1];
            }
            Console.WriteLine(Enumerable.Range(1,b-a).Aggregate((p,v)=>p+v)-b);
        }
}
}