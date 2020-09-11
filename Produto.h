class Produto{
	private:
		char nome_produto[20];
		char modelo[20];
		int quantidade_estoque;
		float preco;
	
	public:
		Produto();
		Produto(char nome_produto[], char modelo[], int quantidade_estoque, float preco);
		
		Produto operator +(int unidades); // Chega ao estoque
		Produto operator -(int unidades); // Venda
		
		void set_name();
		void set_model();
		void set_stock();
		void set_price();
		
		void consultar_produto();
};
