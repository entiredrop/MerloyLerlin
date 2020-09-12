#include <string>
using namespace std;


class Produto{
	private:
		string name_product;
		string model;
		int stock_quantity;
		float price;
	
	public:
		Produto();
		Produto(string nome_produto, string modelo, int quantidade_estoque, float preco);

		Produto operator +(int units); // Chega ao estoque, acesso estoquista e gerente
		Produto operator -(int units); // Venda, acesso ao vendedor e gerente
		
		friend ostream& operator <<(ostream&, const Produto& p);
		friend ostream& operator >>(ostream&, const Produto& p);
		
		Produto set_name();
		Produto set_model();
		Produto set_stock();
		Produto set_price();
		
		int get_stock();
		string get_name();
		string get_model();
		float get_price();
		void get_produt(); // Acesso a todos
		
		void save_product(); //salvo o produto num arquivo "produtos.txt"
};

