#include<iostream>
#include<vector>

int main(int argc, char *argv[]){
	//reading the file
	std::cout<<argv[1]<<std::endl;
	std::cout<<argv[2]<<std::endl;
	std::vector<char> v;
	if (FILE *fp = fopen(argv[2], "r"))
	{
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			v.insert(v.end(), buf, buf + len);
		fclose(fp);
	}

//-c option
	if((std::string)argv[1] == "-c"){
		std::cout<<v.size()<<std::endl;
	}
//-l option
	if((std::string)argv[1] == "-l"){
		int lines = 1;
		for(int i=0;i<v.size();i++){
			if(v[i] == '\n'){
				lines++;
			}
		}

		std::cout<<lines<<std::endl;
	}

//-w option
	if((std::string)argv[1] == "-w"){
		int words = 0;
		for(int i =0;i<v.size();i++){
			if(v[i]==' '){
				words++;
			}
		}
		std::cout<<words+1<<std::endl;
	}
	return 0;
}