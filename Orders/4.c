#include <stdio.h>
#include <stdlib.h>
#include "orders.h"

struct product products[] = {
	{ 1234, "Bread", 2.99 },
	{ 5678, "Milk", 4.19 },
	{ 9012, "Eggs", 3.49 },
	{ 3456, "Butter", 3.99 },
	{ 7890, "Juice", 2.49 },
	{ 2345, "Muffin", 1.49 }
};

int main()
{
	double total = 0; //Initialize total as 0
    short num_orders;
    struct order *orders = read_orders("orders.db", &num_orders);
    if (orders == NULL) {
        printf("Order database does not exist\n");
    }

	for(int i=0; i<num_orders; i++) //loop over the number of orders
	{
		struct order curr_order = orders[i]; //curr_order = current order
		printf("Order ID: %d\n", curr_order.order_id); //print current order ID
		printf("Name: %s\n", curr_order.customer_name); //print current order customer name

		for(int j=0; j<curr_order.num_products; j++) //loop over the number of products
		{
			struct item curr_item = curr_order.product_items[j]; //setting current item to a value in the product_items array
			struct product curr_product; //curr_product = current product

			for(int k = 0; k < 6; k++) //we want to iterate over the products array which has 6 items
			{
				if(curr_item.sku == products[k].sku)//checks if there is a product with a matching sku
				{
					curr_product = products[k];
				}	
			}
			//now we are ready to print the product name, quantity, and price in one line
			printf("%s  %d  %.2f \n", curr_product.name, curr_item.quantity, (curr_product.price*curr_item.quantity));
			total += curr_product.price*curr_item.quantity; //multiply the product price by the quantity
		}
		printf("Total: %.2f\n----------------\n", total); 
		total = 0; //re-initialize total back to 0 for the next order
	}
}
