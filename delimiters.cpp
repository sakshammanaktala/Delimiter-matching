#include <iostream>
#include "project_1.hpp"
void print_program();
bool do_delimiters_nest();
bool does_delimiter_match(char delimiter);
int main();


void print_program()
{
	ece150::start_reading_file();
	while(ece150::at_eof() == false)
		{
		std::cout << ece150::get_next_character();
		}
	//std::cout<<std::endl;
}


bool does_delimiter_match(char delimiter);
bool does_delimiter_match(char delimiter)
{
	bool r=1; //which stores the return value.
	ece150::start_reading_file();
	if (delimiter=='(')
	{
	int i=0;
	while (ece150::at_eof() == false)
	{
	char y = ece150::get_next_character();
	if(i==0 && y==')')
	{
		std::cout << "Unmatched )" << std::endl;
		r=0;
	}
	if(i!=0 && y == ')')
		{i--;}
	else if (y == '(')
		i++;
	}
	if(i<0)
	{
				while(i<0){
			std::cout << "Unmatched )" << std::endl;
					i++;
				}
				r=0;
			}
	else if (i>0)
	{   std::cout << "Missing ";

		while(i>0){
		std::cout << ")";
			i--;
		}
		r=0;
		std::cout << std::endl;
	}
	return r;
	}



	if (delimiter=='{')
		{
		int j=0;
		while (ece150::at_eof() == false){
		char y = ece150::get_next_character();
		if(j==0 && y=='}')
			{
				std::cout << "Unmatched }" << std::endl;
				r=0;
			}
		if(j!=0 && y == '}')
				{j--;}
		else if (y == '{')
			j++;
		}
		if(j<0)
		{
			while(j<0)
				{
				std::cout << "Unmatched }" << std::endl;
				j++;
				}
			r=0;
		}
		else if (j>0)
		{   std::cout << "Missing ";

			while(j>0){
			std::cout << "}";
				j--;
			}
			r=0;
			std::cout << std::endl;
		}
		return r;
		}



	if (delimiter=='[')
		{
		int k=0;
		while (ece150::at_eof() == false){
		char y = ece150::get_next_character();
		if(k==0 && y==']')
		{
		std::cout << "Unmatched ]" << std::endl;
		r=0;
		}
		if(k!=0 && y == ']')
		k--;
		else if (y == '[')
			k++;
		}
		if(k<0)
		{
			while(k<0){
		std::cout << "Unmatched ]" << std::endl;
				k++;
			}
			r=0;
		}
		else if (k>0)
		{	std::cout << "Missing ";

			while(k>0){
			std::cout << "]";
				k--;
			}
			r=0;
			std::cout << std::endl;
		}
		return r;
		}
	return false;
}

bool do_delimiters_nest()
{
	ece150::start_reading_file();
	ece150::initialize_table();
	while(ece150::at_eof()==false)
	{
	char y = ece150::get_next_character();
	if(y=='('||y=='['||y=='{')
		ece150::place_character(y);
	else if (y==')')
				{
				if ('('== ece150::get_right_most_character())
				ece150::erase_right_most_character();
				else{
					std::cout<<"Unmatched " << y << std::endl;
					}
				}
	else if (y==']')
					{
					if ('['== ece150::get_right_most_character())
					ece150::erase_right_most_character();
					else{
						std::cout<<"Unmatched " << y <<std::endl;
						}
					}
	else if (y=='}')
					{
					if ('{'== ece150::get_right_most_character())
					ece150::erase_right_most_character();
					else{
						std::cout<<"Unmatched " << y << std::endl;
						}
					}
			}
		if (ece150::is_table_empty() == false)
		 {
			std::cout<< "Missing ";
			while(ece150::is_table_empty() == false ){
				if(ece150::get_right_most_character() == '{')
					std::cout<< "}";
				else if(ece150::get_right_most_character() == '[')
									std::cout<< "]";
				if(ece150::get_right_most_character() == '(')
									std::cout<< ")";
				ece150::erase_right_most_character();
			}
			std::cout<< std::endl;
			return false;
			std::cout<< std::endl;
		}
	return true;
}




int main() {
print_program();
std::cout << does_delimiter_match( '(' ) << std::endl;
std::cout << does_delimiter_match( '[' ) << std::endl;
std::cout << does_delimiter_match( '{' ) << std::endl;
std::cout << do_delimiters_nest() << std::endl;
return 0;
}


