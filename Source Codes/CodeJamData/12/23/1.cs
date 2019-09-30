using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Jam23
{
    class Program
    {
        const string FileName = @"D:\C-large.in";
        public const string outputFileName = @"D:\C-large-out.in";

        static void Main(string[] args)
        {
            var builder = new StringBuilder();

            using (var sr = new StreamReader(FileName))
            {
                String line;
                line = sr.ReadLine();
                int caseCounter = 1;
                while ((line = sr.ReadLine()) != null)
                {
                    builder.AppendLine("Case #" + caseCounter + ":");

                    string[] data = line.Split(' ');
                    ulong[] uData = new ulong[Int32.Parse(data[0])];

                    for (int i = 1; i < data.Length; i++) 
                    {
                        uData[i-1] = UInt64.Parse(data[i]);
                    }

                    processCase(uData, builder);

                    caseCounter++;
                }
            }

            using (var sw = new StreamWriter(outputFileName))
            {
                sw.Write(builder.ToString());
            }

            Console.WriteLine("Done...");
            Console.ReadKey();
        }

        static void processCase(ulong[] uData, StringBuilder builder)
        {
            var hash = new Dictionary<ulong, List<string>>();
            bool done = false;

            foreach (var u in uData)
            {
                hash.Add(u, new List<string>(new[] { u.ToString() + " " }));
            }

            // идем последовательно увеличивая длину строки
            #region
            for (int i = 1; i < uData.Length && !done; i++)
            {
                // по всем ключам которые уже посчитаны
                ulong[] hashKeys = hash.Keys.ToArray();
                foreach (var k in hashKeys)
                {
                    // берем каждую строку формирующую такую сумму-ключ
                    foreach (var item in hash[k])
                    {
                        // если длина "наша"
                        if (item.Length == i)
                        {
                            // перебираем весь массив чисел
                            for (int j = 0; j < uData.Length; j++)
                            {
                                // если строка не содержит такое число - его надо добавить в строку
                                #region
                                if (!item.Contains(uData[j] + " "))
                                {
                                    // смотрим новый ключ - с таким числом
                                    var newKey = k + uData[j];
                                    // если такого ключа нет в словаре - добавляем
                                    if (!hash.ContainsKey(newKey))
                                    {
                                        hash.Add(newKey, new List<string>(new[] { item + uData[j] + " " }));
                                    }
                                    // если есть - проверяем есть ли у существующих значений пересечений с item + uData[j] + ","
                                    else
                                    {
                                        var it = new List<string>(item.Split(new [] {" "}, 500, StringSplitOptions.RemoveEmptyEntries));
                                        it.Add(uData[j].ToString());
                                        foreach (var s in hash[newKey])
                                        {
                                            bool noIntersect = true;
                                            var oldData = s.Split(new[] { " " }, 500, StringSplitOptions.RemoveEmptyEntries);
                                            foreach (var old in oldData)
                                            {
                                                if (it.Contains(old))
                                                {
                                                    noIntersect = false;
                                                    break;
                                                }
                                            }
                                            if (noIntersect)
                                            {
                                                builder.AppendLine(item + uData[j]);
                                                builder.AppendLine(s);
                                                done = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                #endregion

                                if (done) break;
                            }
                        }
                        if (done) break;
                    }
                    if (done) break;
                }
            }
            #endregion

            if (!done) builder.AppendLine("Impossible");
        }
    }
}
