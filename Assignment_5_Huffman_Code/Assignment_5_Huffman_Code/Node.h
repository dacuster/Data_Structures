#pragma once
class Node
{
public:
	Node(char _data);
	~Node();

	const size_t getFrequency() { return frequency; }
	char getData() { return data; }

	const bool operator<(const Node& _comparison) const { return this->frequency < _comparison.frequency; }

private:
	char data = NULL;
	size_t frequency = 1;
	Node* left = nullptr;
	Node* right = nullptr;
};

