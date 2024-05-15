#pragma once

typedef void* (*create_client_class_fn)(int entity_index, int serial_number);
typedef void* (*create_event_fn)();

class c_client_class
{
public:
	create_client_class_fn create_client_class;
	create_event_fn create_event;
	char* network_name;
	void* recv_table;
	c_client_class* next;
	int class_id;
};