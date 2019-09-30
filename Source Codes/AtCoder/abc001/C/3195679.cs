using System;
	class program{
      static void Main(string[] args){
        string[] w = Console.ReadLine().Split(' ');
        double deg = double.Parse(w[0]);
        double dis = double.Parse(w[1]);
        
        if(dis <= 14){
          Console.WriteLine("C 0");
        }else{
          //???
          //???????????????????for?????????
          	if(deg<113){		Console.Write("N ");
			}else if(deg<338){	Console.Write("NNE ");
			}else if(deg<563){	Console.Write("NE ");
			}else if(deg<788){	Console.Write("ENE ");
			}else if(deg<1013){	Console.Write("E ");
			}else if(deg<1238){	Console.Write("ESE ");
			}else if(deg<1463){	Console.Write("SE ");
			}else if(deg<1688){	Console.Write("SSE ");
			}else if(deg<1913){	Console.Write("S ");                         
			}else if(deg<2138){	Console.Write("SSW ");                          
			}else if(deg<2363){	Console.Write("SW ");                          
			}else if(deg<2588){	Console.Write("WSW ");                          
			}else if(deg<2813){	Console.Write("W ");                          
			}else if(deg<3038){	Console.Write("WNW ");                          
			}else if(deg<3263){	Console.Write("NW ");                          
			}else if(deg<3488){	Console.Write("NNW ");
			}else			  {	Console.Write("N ");
    	    }
          	//??
	        double x = Math.Floor(dis/6+0.5);
          	if(x<16){			Console.WriteLine("1");
            }else if(x<34){		Console.WriteLine("2");
            }else if(x<55){		Console.WriteLine("3");                
            }else if(x<80){		Console.WriteLine("4");                
            }else if(x<108){	Console.WriteLine("5");                
            }else if(x<139){	Console.WriteLine("6");                
            }else if(x<172){	Console.WriteLine("7");                
            }else if(x<208){	Console.WriteLine("8");                
            }else if(x<245){	Console.WriteLine("9");                
            }else if(x<285){	Console.WriteLine("10");                
            }else if(x<327){	Console.WriteLine("11");                
            }else 			{	Console.WriteLine("12");             
            }                
        }
      }
    }