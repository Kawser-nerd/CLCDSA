class Program{
  static void Main(string[] args){
	var array = System.Console.ReadLine().Split(' ');
  	System.Console.WriteLine(int.Parse(array[0])^int.Parse(array[1])^int.Parse(array[2]));
  }
}