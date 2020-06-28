#include<iostream>
#include"symbol.h"
#include<vector>
using namespace std;
void init_symbol();

sym_table symbol_table;
vector<length_table_item*>length_table;
int main() {
	init_symbol();
	item* it = symbol_table.get_symbol("a");
	if (it != NULL) {
		length_table_item* len_addr = (length_table_item*)it->addr;
		cout << it->name << "\t" << len_addr->length << endl;
	}
	return 0;
}

void init_symbol() {
	length_table_item* a_len = new length_table_item(sizeof(int));
	length_table.push_back(a_len);
	symbol_table.add_symbol("a", NULL, v_cat, a_len);
}