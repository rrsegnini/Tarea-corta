#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int LeerArchivo()
	{
	
	/*                                   
	
	//Este es el que lee línea por línea[
	
	string line;
  	ifstream myfile ("Arch1.txt");
  	if (myfile.is_open())
  		{
    	while ( getline (myfile,line) )
    		{
      		cout << line << '\n'; //En line está la línea del .txt
    		}
    	myfile.close();
  		}

  	else cout << "Unable to open file"; 

  	return 0;
  	]*/
	
	
  	//Este es el que lo lee todo pegado[
  	char str[256];

	//std::cout << "Arch1.txt";
	//std::cin.get (str,256);    // get c-string
	
	std::ifstream is("Arch1.txt");     // open file
	
	char c;
	  
	while (is.get(c))          // loop getting single characters
		//if (c == 'o')
			std::cout << c << "\n";
	
	is.close();                // close file
	
	return 0;
  	//]
  	
	}

