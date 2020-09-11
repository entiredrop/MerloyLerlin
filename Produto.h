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
		
		void set_name();
		void set_model();
		void set_stock();
		void set_price();
		
		void get_produt(); // Acesso a todos
		
		void save_product(); //salvo o produto num arquivo "produtos.txt"
};

