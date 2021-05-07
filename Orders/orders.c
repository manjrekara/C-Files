#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#include "orders.h"

struct order * read_orders(const char *filename, short *num_orders)
{
    int fd;
    fd = open(filename, O_RDONLY);
    int err = fd;
    if (err == -1) {
        return NULL;
    }

    read(fd, num_orders, sizeof(*num_orders));
    struct order *orders = (struct order *)
        calloc(*num_orders, sizeof(struct order));

    int i;
    for (i=0; i<*num_orders; i++) {
        struct order *op = &orders[i];
        read(fd, &op->order_id, sizeof(op->order_id));

        uint32_t sz;
        read(fd, &sz, sizeof(sz));
        op->customer_name = (char *)malloc(sz+1);
        read(fd, op->customer_name, sz);
        op->customer_name[sz] = 0;

        read(fd, &op->num_products, sizeof(op->num_products));
        op->product_items = (struct item *)
            calloc(op->num_products, sizeof(struct item));

        int j;
        for (j=0; j<op->num_products; j++) {
            struct item *ip = &(op->product_items[j]);
            read(fd, &ip->sku, sizeof(ip->sku));
            read(fd, &ip->quantity, sizeof(ip->quantity));
        }
    }

    close(fd);
    return orders;
}

