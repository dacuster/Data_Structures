#pragma once
class Comparison;

class Huffman
{
public:
	Huffman() { root = nullptr; }
	Huffman(std::string _phrase);
	~Huffman();

	void print(Node* _root, std::string _phrase);
	void generate(std::map<char, size_t> _characterMap);

private:
	Node* root = nullptr;
	t_huffmanQueue queue;

	void calculateFrequency(std::string _phrase);
};

class Comparison
{
public:
	Comparison() { }
	bool operator()(const Node& _left, const Node& _right) const
	{
		return (_left < _right);
	}
};

typedef std::priority_queue<Node, std::vector<Node>, Comparison> t_huffmanQueue;
