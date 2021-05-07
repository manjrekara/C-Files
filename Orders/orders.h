struct product {
	short sku;
	char *name;
	float price;
};

struct item {
	short sku; //refers to a product in the products array
	short quantity;
};

struct order 
{
	short order_id;
	char *customer_name;
	short num_products;
	struct item *product_items;
};

struct order * read_orders(const char *filename, short *num_orders);

