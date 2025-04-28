#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct order {
    char coffee_item_names[MAX_ITEMS][100];
    char snacks_names[MAX_ITEMS][100];
    char softDrinks_names[MAX_ITEMS][100];
    float coffee_item_prices[MAX_ITEMS];
    float snack_item_prices[MAX_ITEMS];
    float softDrink_item_prices[MAX_ITEMS];
};

struct cart {
    char item_names[MAX_ITEMS][100];
    float item_prices[MAX_ITEMS];
    int item_count;
};

void display_menu(int total_coffee, int total_snacks, int total_soft_drinks, struct order *shop_order) {
    printf("\n\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Available Items in Shop::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n\t\t\tCoffee Items \t\t\t\tSnack Items \t\t\tSoft Drink Items\n");
    printf("\t------------------------------------------------------------------------------------------------------------------------------------------------\n");

    int max_items = total_coffee > total_snacks ? (total_coffee > total_soft_drinks ? total_coffee : total_soft_drinks) : (total_snacks > total_soft_drinks ? total_snacks : total_soft_drinks);
    for (int i = 0; i < max_items; i++) {
        if (i < total_coffee) {
            printf("\t%d.%-20s ($%.2f)", i + 1, shop_order->coffee_item_names[i], shop_order->coffee_item_prices[i]);
        } else {
            printf("\t%-20s", "");
        }
        if (i < total_snacks) {
            printf("\t\t%d.%-20s ($%.2f)", i + 1, shop_order->snacks_names[i], shop_order->snack_item_prices[i]);
        } else {
            printf("\t\t%-20s", "");
        }
        if (i < total_soft_drinks) {
            printf("\t\t%d.%-20s ($%.2f)", i + 1, shop_order->softDrinks_names[i], shop_order->softDrink_item_prices[i]);
        } else {
            printf("\t\t%-20s", "");
        }
        printf("\n");
    }
    printf("\t------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void add_item_to_cart(struct cart *customer_cart, struct order *shop_order, int total_coffee, int total_snacks, int total_soft_drinks) {
    char item_name[100];
    int item_found = 0;
    printf("\nEnter the item name: ");
    fgets(item_name, 100, stdin);
    item_name[strcspn(item_name, "\n")] = 0;

    for (int i = 0; i < total_coffee; i++) {
        if (strcmp(item_name, shop_order->coffee_item_names[i]) == 0) {
            strcpy(customer_cart->item_names[customer_cart->item_count], item_name);
            customer_cart->item_prices[customer_cart->item_count] = shop_order->coffee_item_prices[i];
            customer_cart->item_count++;
            item_found = 1;
            break;
        }
    }
    if (!item_found) {
        for (int i = 0; i < total_snacks; i++) {
            if (strcmp(item_name, shop_order->snacks_names[i]) == 0) {
                strcpy(customer_cart->item_names[customer_cart->item_count], item_name);
                customer_cart->item_prices[customer_cart->item_count] = shop_order->snack_item_prices[i];
                customer_cart->item_count++;
                item_found = 1;
                break;
            }
        }
    }
    if (!item_found) {
        for (int i = 0; i < total_soft_drinks; i++) {
            if (strcmp(item_name, shop_order->softDrinks_names[i]) == 0) {
                strcpy(customer_cart->item_names[customer_cart->item_count], item_name);
                customer_cart->item_prices[customer_cart->item_count] = shop_order->softDrink_item_prices[i];
                customer_cart->item_count++;
                item_found = 1;
                break;
            }
  }
    }
    if (!item_found) {
        printf("Item not found in shop.\n");
    } else {
        printf("Item added to cart.\n");
    }
}

int main() {
    int total_coffee, total_soft_drinks, total_snacks, i;
    struct order shop_order;
    char cc;

    printf("1.Do You Want To Use Pre-Declared Menu '(Y)' \n2.Want To Make Own Menu '(N)': ");
    scanf(" %c", &cc);
     getchar();

    if (cc == 'y' || cc == 'Y') {
        char ccoffee_names[25][100] = { "Espresso", "Americano", "Latte", "Cappuccino", "Macchiato", "Mocha", "Flat White", "Long Black", "Ristretto", "Affogato", "Irish Coffee", "Café au Lait", "Turkish Coffee", "Greek Coffee", "Cold Brew", "Nitro Coffee", "French Press", "Moka Pot", "Drip Coffee", "Pour Over", "Chemex", "Aeropress", "Instant Coffee", "Vietnamese Coffee", "Cafe Cubano", "Cafe de Olla" };
        float ccoffee_prices[25] = { 100, 120, 130, 140, 160, 180, 200, 220, 250, 280, 300, 320, 340, 360, 380, 400, 420, 440, 460, 480, 500, 520, 540, 560, 580, 600 };
        char ssnack_names[25][100] = { "Muffin", "Sandwich", "Croissant", "Bagel", "Scone", "Danish", "Biscotti", "Donut", "Brownie", "Cheesecake", "Cupcake", "Macaroon", "Cannoli", "Tart", "Eclair", "Churros", "Pretzel", "Quiche", "Empanada", "Samosa", "Spring Roll", "Chicken Wings", "Mozzarella Sticks", "Nachos", "Popcorn", "Granola Bar" };
        float ssnack_prices[25] = { 150, 180, 200, 220, 250, 280, 300, 320, 340, 360, 380, 400, 420, 440, 460, 480, 500, 520, 540, 560, 580, 600, 620, 640, 660, 680 };
        char ssoft_drink_names[25][100] = { "Cola", "Lemonade", "Iced Tea", "Orange Soda", "Ginger Ale", "Root Beer", "Cream Soda", "Fruit Punch", "Grape Soda", "Apple Soda", "Cherry Soda", "Blue Raspberry Soda", "Strawberry Soda", "Lime Soda", "Lemon-Lime Soda", "Tonic Water", "Club Soda", "Sparkling Water", "Seltzer Water", "Ginger Beer", "Kombucha", "Energy Drink", "Sports Drink", "Apple Juice", "Orange Juice", "Cranberry Juice" };
        float ssoft_drink_prices[25] = { 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 420, 440, 460, 480, 500, 520, 540, 560, 580 };

        for (i = 0; i < 25; i++) {
            strcpy(shop_order.coffee_item_names[i], ccoffee_names[i]);
            shop_order.coffee_item_prices[i] = ccoffee_prices[i];
            strcpy(shop_order.snacks_names[i], ssnack_names[i]);
            shop_order.snack_item_prices[i] = ssnack_prices[i];
            strcpy(shop_order.softDrinks_names[i], ssoft_drink_names[i]);
            shop_order.softDrink_item_prices[i] = ssoft_drink_prices[i];
        }

        total_coffee = total_snacks = total_soft_drinks = 25;
    }

    if (cc != 'y' && cc != 'Y') {
        printf("\nEnter total coffee varieties you have available in shop: ");
        scanf("%d", &total_coffee);
        getchar();
        for (i = 0; i < total_coffee; i++) {
            printf("Enter name for coffee item %d: ", i + 1);
            fgets(shop_order.coffee_item_names[i], 100, stdin);
            shop_order.coffee_item_names[i][strcspn(shop_order.coffee_item_names[i], "\n")] = 0;
            printf("Enter price for coffee item %d: $", i + 1);
            scanf("%f", &shop_order.coffee_item_prices[i]);
            getchar();
        }

        printf("\nEnter total snack varieties you have available in shop: ");
        scanf("%d", &total_snacks);
        getchar();
        for (i = 0; i < total_snacks; i++) {
            printf("Enter name for snack item %d: ", i + 1);
            fgets(shop_order.snacks_names[i], 100, stdin);
            shop_order.snacks_names[i][strcspn(shop_order.snacks_names[i], "\n")] = 0;
            printf("Enter price for snack item %d: $", i + 1);
            scanf("%f", &shop_order.snack_item_prices[i]);
            getchar();
        }

        printf("\nEnter total soft drink varieties you have available in shop: ");
        scanf("%d", &total_soft_drinks);
        getchar();
        for (i = 0; i < total_soft_drinks; i++) {
            printf("Enter name for soft drink item %d: ", i + 1);
            fgets(shop_order.softDrinks_names[i], 100, stdin);
            shop_order.softDrinks_names[i][strcspn(shop_order.softDrinks_names[i], "\n")] = 0;
            printf("Enter price for soft drink item %d: $", i + 1);
            scanf("%f", &shop_order.softDrink_item_prices[i]);
            getchar();
        }
    }

    new_item:
    display_menu(total_coffee, total_snacks, total_soft_drinks, &shop_order);
    struct cart customer_cart = { .item_count = 0 };
    char order_type;

    do {
        printf("\n::Press 'A' to add an item to your cart or 'C' to checkout: ");
        scanf(" %c", &order_type);
        getchar();
        if (order_type == 'A' || order_type == 'a') {
            add_item_to_cart(&customer_cart, &shop_order, total_coffee, total_snacks, total_soft_drinks);
        }
    } while (order_type != 'C' && order_type != 'c');

    float total_price = 0;
    for (i = 0; i < customer_cart.item_count; i++) {
        total_price += customer_cart.item_prices[i];
    }

    cart:
    printf("\n\n\t:::::::Cart Summary:::::::\n");
    for (i = 0; i < customer_cart.item_count; i++) {
        printf("\t%s ($%.2f)\n", customer_cart.item_names[i], customer_cart.item_prices[i]);
    }
    printf("\t|-------------------------|\n");
    printf("\t|Total Price: $%.2f\t |\n", total_price);
    printf("\t|-------------------------|\n");

    char place_order;
    char recheck, reconf;
    int reconff;
    printf("\nDo you want to place the order? (Y/N): ");
    scanf(" %c", &place_order);
    getchar();

    if (place_order == 'Y' || place_order == 'y') {
        printf("\tOrder placed successfully.\n");
        printf("'\It was a pleasure serving you today!'\n");
    } else {
        printf("\n\n\t\t\t\t\t\t!!! Attention Please !!!\n");
        printf("\t\tConfirmation is you canceled this order, for 'Yes' Press 'Y' If you don't 'No' Press 'N' : ");
        scanf(" %c", &recheck);
        getchar();
        if(recheck == 'y' || recheck == 'Y') {
            printf("'We understand sometimes the perfect item isn't always here, but we hope to see you again soon-have a great day!'");
        } else if(recheck == 'n' || recheck == 'N') {
            printf("Do you want to continue your order 'Y/N' : ");
            scanf(" %c",&reconf);
            getchar();
            if(reconf == 'y' || reconf == 'Y') {
                printf("\n\n1. To continue with 'Old' cart item, press '1'.\n\t\tOR\n2. To create new cart, press '2' : ");
                scanf("%d",&reconff);
                getchar();
                if(reconff == 1) {
                    goto cart;
                } else if(reconff == 2) {
                    goto new_item;
                }
            } else {
                printf("'Even if today wasn't the day, we'll be ready for you when it is! Hope to see you soon!'");
            }
        }
    }

    return 0;
}
