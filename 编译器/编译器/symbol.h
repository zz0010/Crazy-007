#pragma once
#ifndef _symbol_H
#define _symbol_H

#include<string>
#include<unordered_map>

struct array_table_item;
struct struct_table_item;
struct type_table_item;
struct symbol_table_item;
struct length_table_item;
struct const_int_table_item;
struct const_char_table_item;
struct const_string_table_item;
struct para_table_item;
struct function_table_item;
struct vall_table_item;

enum symbol_cat {
	func_cat, const_cat, type_cat, domain_cat, v_cat, vn_cat, vf_cat
};

enum TVAL	//类型表类码
{
	int_type, real_type, char_type, bool_type, array_type, struct_type
};



struct array_table_item {
	int low;
	int up;
	int length;
	type_table_item* type_pointer;
	array_table_item(int up, int length, int low = 0, type_table_item* type_pointer = NULL) {
		this->up = up;
		this->length = length;
		this->type_pointer = type_pointer;
	}
};

struct struct_table_item {
	std::string name;
	int offset;
	type_table_item* type_pointer;
	struct_table_item(std::string name, int offset, type_table_item* type_pointer = NULL) {
		this->name = name;
		this->offset = offset;
		this->type_pointer = type_pointer;
	}
};

struct type_table_item {
	TVAL type_code;
	void* data_type_pointer;
	type_table_item(TVAL type_code, void* data_type_pointer) {
		this->type_code = type_code;
		this->data_type_pointer = data_type_pointer;
	}
};

struct symbol_table_item {
	std::string name;
	type_table_item* type;
	symbol_cat cat;
	void* addr;
	symbol_table_item(){}
	symbol_table_item(std::string name, type_table_item* type, symbol_cat cat, void * addr = NULL) {
		this->name = name;
		this->type = type;
		this->cat = cat;
		this->addr = addr;
	}
};

struct length_table_item {
	int length;
	length_table_item(int length):length(length){}
};

struct const_int_table_item {
	int num;
	const_int_table_item(int num):num(num){}
};

struct const_char_table_item {
	char ch;
	const_char_table_item(char ch):ch(ch){}
};

struct const_string_table_item {
	std::string str;
	const_string_table_item(std::string str):str(str){}
};

struct para_table_item {
	symbol_table_item* para;
	para_table_item(symbol_table_item* para):para(para){}
};

struct function_table_item {
	int level;		//层次号
	int offset;		//区距
	int paras_num;	//参数个数
	para_table_item* para_table;
	function_table_item(int level, int offset, int paras_num, para_table_item* para_table) {
		this->level = level;
		this->offset = offset;
		this->paras_num = paras_num;
		this->para_table = para_table;
	}

};

struct vall_table_item {
	vall_table_item* old_sp;
};

class sym_table {
public:
	void add_symbol(std::string name, type_table_item* type, symbol_cat cat, void* addr) {
		symbol_table_item tem_item(name, type, cat, addr);
		table[name] = tem_item;
	}
	symbol_table_item* get_symbol(std::string name) {
		auto search = table.find(name);
		if (search == table.end()) {
			return NULL;
		}
		else {
			return &(search->second);
		}
	}
private:
	std::unordered_map<std::string, symbol_table_item> table;

};

class len_table {
public:

private:
	vector<length_table_item*> table;
};

typedef symbol_table_item item;

class total_symbol_table {
public:
	template<typename T>
	void add_variable(T name) {

	}
};

#endif // !_symbol_H
