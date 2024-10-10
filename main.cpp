#include<iostream>
#include<vector>

int getBytes(std::vector<char> v){
	return v.size();
}

int getLines(std::vector<char> v){
	if(v.size()==0){return 0;}
	int lines = 1;
		for(int i=0;i<v.size();i++){
			if(v[i] == '\n'){
				lines++;
			}
		}

	return lines;
}

int getWords(std::vector<char> v){
	if(v.size()==0){return 0;}
	int words = 1;
		for(int i =0;i<v.size();i++){
			if(v[i]==' '){
				words++;
			}
		}
		return words;
}

int main(int argc, char *argv[]){

	std::vector<char> v;
	std::string option;

	if(argc == 1 || (argc == 2 && *argv[1] == '-')){
		//take standard input
		char c;
		while( c=getchar() != '#'){
			v.push_back(c);
		}
		option = argc==1?"":(std::string)argv[1];
	}

	else{

	//reading the file
	std::string filename;
	filename = argc==2?(std::string)argv[1]:(std::string)argv[2];
	option = argc==2?"":(std::string)argv[1];
	if (FILE *fp = fopen(filename.c_str(), "r"))
	{
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			v.insert(v.end(), buf, buf + len);
		fclose(fp);
	}
	}

//default option -c -l -w
	if(option.size()==0){
		std::cout<<getBytes(v)<<" "<<getLines(v)<<" "<<getWords(v)<<std::endl;
	}
//-c option
	if(option == "-c" || option == "-m"){
		std::cout<<getBytes(v)<<std::endl;
	}
//-l option
	if(option == "-l"){
		std::cout<<getLines(v)<<std::endl;
	}

//-w option
	if(option == "-w"){
		std::cout<<getWords(v)<<std::endl;
	}


	return 0;
}