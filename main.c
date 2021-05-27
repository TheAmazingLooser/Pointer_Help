#include <stdio.h>

// Kleine Funktion zur Vorschau von Werte-Kopien.
void Vorschau1()
{
    // Anlegen von "a" und "b".
    int a = 0; // "a" ist standartmäsig 0
    int b = 1; // "b" ist standartmäsig 1

    printf("%d - %d\n", a,b);   // Ausgeben der Werte von "a" und "b"
    printf("%p - %p\n", &a,&b); // Ausgeben der Adressen von "a" und "b"

    // a gleich b setzen (Digga, das eskaliert hier komplett o.O)
    a = b;

    // Kleinen Trennstrich anzeigen (nur fürs Visuelle, das hier ist keine Vodoo-Zauber oder :dreckigeschmutzdricks: )
    printf("------------------------------\n");

    /*
        "a" ist jetzt 1. Hat seine Adresse allerdings behalten.
        Um das zu beweisen, gebe ich einfach nochmal die Werte und Adressen aus.
    */
    printf("%d - %d\n", a,b);   // Ausgeben der Werte von "a" und "b"
    printf("%p - %p\n", &a,&b); // Ausgeben der Adressen von "a" und "b"

    /*
        Die Adresse von a ist tatsächlich die selbe wie davor. Das bedeutet, das der Wert von b nach a Kopiert wurde.
        Also gibt es im Speicher jetzt 2 mal den selben int-Wert auf 2 unterschiedlichen Adressen. (Die Adressen von "a" und "b")
    */
}

void Vorschau2_printArray(int *int_array, int Size)
{
    if (Size <= 0)
    {
        printf("Array ist leer!\n");
        return;
    }

    // Der Schönheit wegen gebe ich erst das erste Element des Arrays aus (das gibt es ja, sonst würde unsere if von oben returnen)
    printf("%d",int_array[0]);

    for(int i = 1; i < Size; i++) // Beginnend bei index 1 (also bei dem 2. Element), den Rest des Arrays ausgeben.
    {
        printf(", %d", int_array[i]);
    }
}
void Vorschau2()
{
    // Zwei int-Array's erstellen und diese in a und b zuweisen.
    // Beide Variablen haben damit ihre eigene Adresse im Speicher
    int a[] = {0,1,2,3,4,5};
    int b[] = {5,4,3,2,1,0};

    // Da ein Array (von egal welchem Typ) eben nicht kopiert wird, sind "a" und "b" indirekt Pointer,
    // Zwar sind die hier noch Arrays und werden als solche Behandelt, werden aber automatisch in ein Pointer umgewandelt sobald diese in eine Variable oder als Parameter angegeben werden.
    // "a" und "b" sind also Array welche automatisch in ein Pointer umgewandelt werden, wenn dies notwendig ist.
    // Es ist also ohne weiteres möglich, einen int-Pointer gleich "a" oder "b" zu setzen.

    // Man kann nicht direkt alle Werte von "a" oder "b" ausgeben lassen, weil C nicht weiß wie groß das Array ist und somit diese nicht dynamisch ausgeben kann.
        // Weil ja Arrays beim angeben als Parameter einer Funktion in einen echten Pointer umgewandelt werden.
    // Allerdings werden "a" und "b" hier frisch erzeugt. Da weiß das Programm noch wie viel Speicher "a" und "b" verwenden (hier sind sie noch echte Arrays).
    // Man könnte also die Größe wie folgt ausrechnen lassen: int size = sizeof(a) / sizeof(int);
    printf("a und b erstellt\n");
    printf("%p - %p\n", a,b);

    // Das ist eine schönere Ansicht in der Konsole für die Ausgabe eines Arrays
    printf("a = {");
    Vorschau2_printArray(a, 6);
    printf("};\n");

    // Das ganze auch für "b" :3
    printf("b = {");
    Vorschau2_printArray(b, 6);
    printf("};\n");

    /*
        "a" und "b" haben bei den Print zwar die selben Werte, aber andere Adressen.
    */

    // Kleinen Trennstrich anzeigen (nur fürs Visuelle)
    printf("------------------------------\n");
    printf("Einen Wert von a geaendert\n");

    // Weil "a" eine andere Adresse als "b" hat, kann ich einen Wert in "a" ändern ohne das ein Wert in "b" geändert ist.
    // Die Änderung eines Wertes in "a" ändert NICHT dessen Adresse!
    a[2] = 10;

    // Ausgabe der Daten
    printf("%p - %p\n", a,b);

    // Array-Ausgabe für "a"
    printf("a = {");
    Vorschau2_printArray(a, 6);
    printf("};\n");

    // Array-Ausgabe für "b"
    printf("b = {");
    Vorschau2_printArray(b, 6);
    printf("};\n");

    /*
        Für "a" hat sich der dritte Wert geändert. Dieser ist jetzt 10 anstatt 2. Bei "b" hat sich nichts geändert, es ist gleich geblieben.
        Die Adressen von "a" und "b" haben sich ebenfalls nicht geändert.
    */

    printf("------------------------------\n");
    printf("Variable c auf die Adresse von a gelegt\n");

    // Da "a" und "b" im Speicher registriert sind, haben diese eine Adresse.
    // Diese Adresse kann man jetzt jederzeit einer neuen Pointer-Variable zuweisen.
    // ACHTUG: Ihr könnt nicht die Adresse der Adresse von "a" oder "b" machen (also sowas &&a ist nicht valide!). Eine Adresse hat keine Adresse im Speicher.
    // Nur eine Variable hat eine Adresse im Speicher. Da "a" ein Array ist, hat diese Variable auch eine Adresse im Speicher.
    // Bei der Zuweisung zu einer neuen Variable wird wiegesagt nichts kopiert, es wird einfach die Startadresse des Arrays weitergegeben.
        // Deswegen sind Arrays implizit auch Pointer.
    int *c = a;

    // "c" ist jetzt ein Pointer auf die Startadresse von a. Die Adresse von "c" (&c) ist jetzt die Adresse im Speicher, wo "c" liegt.
    // Wenn ich also jetzt die Adresse von "c" ändern würde, dann ändert es auch NUR DIE ADRESSE von "c"! (Keine Andere Variable)

    // "a", "b" und "c" ausgeben:
    printf("%p - %p - %p\n", a,b,c);

    // Array-Ausgabe für "a"
    printf("a = {");
    Vorschau2_printArray(a, 6);
    printf("};\n");

    // Array-Ausgabe für "b"
    printf("b = {");
    Vorschau2_printArray(b, 6);
    printf("};\n");

    // Array-Ausgabe für "c"
    printf("c = {");
    Vorschau2_printArray(c, 6);
    printf("};\n");

    /*
        Wir sehen, das die Adressen von "a" und "c" identisch sind, genau wie die Daten auch. Nur "b" behält seine eigenen Daten.
    */

    printf("------------------------------\n");
    printf("Daten von c aendern auch Daten von a!\n");
    c[3] = 13;

    printf("%p - %p\n", a,c);

    // Array-Ausgabe für "a"
    printf("a = {");
    Vorschau2_printArray(a, 6);
    printf("};\n");

    // Array-Ausgabe für "c"
    printf("c = {");
    Vorschau2_printArray(c, 6);
    printf("};\n");


    printf("------------------------------\n");
    printf("Variable c auf die Adresse von b gelegt\n");
    // Wenn wir jetzt die Adresse von "c" ändern, dann ändert sich die Adresse von "a" allerdings NICHT!
    // Für dieses Beispiel setzte ich "c" einfach mal zu "b".
    c = b;

    // "a", "b" und "c" ausgeben:
    printf("%p - %p - %p\n", a,b,c);

    // Array-Ausgabe für "a"
    printf("a = {");
    Vorschau2_printArray(a, 6);
    printf("};\n");

    // Array-Ausgabe für "b"
    printf("b = {");
    Vorschau2_printArray(b, 6);
    printf("};\n");

    // Array-Ausgabe für "c"
    printf("c = {");
    Vorschau2_printArray(c, 6);
    printf("};\n");
    /*
        "a" hat seine original Adresse behalten. "c" hat die Adresse von "b" angenommen und die Daten von "c" und "b" sind jetzt identisch.
        Das heißt, wenn man die Adresse einer Pointer-Variable ändert, dann ändert es auch NUR die Adresse von DIESER Varaible!
    */

    printf("------------------------------\n");
    printf("*d auf a gesetzt (und somit automatisch c und *e ueberschrieben)\n");

    // Jetzt kommt der Vodoo Zauber der Pointer.

    // Oben habe ich gezeigt, wie die Daten eines Pointers und damit auch die Daten des selben Pointers allerdings einer anderen Variable geändert werden können.
    // Jetzt gehe ich einen Schritt weiter und nutze Doppel-Pointer. Das Prinzip bleibt das gleiche:
        // Eine Variable hat IMMER seine EIGENE Adresse im Speicher, welche Daten sie beinhält (einen Pointer, oder direkt Daten) ist dabei egal.
        // Ein Doppel-Pointer ist dabei nur eine Variable (als Pointer), welche auf einen andere Pointer zeigt und dieser Zeigt dann auf Daten.
    int **d = &c;
    int **e = &c;

    // Zum beweis das sich hier was ändert (ausgeben von "c", das sollte aktuell "b" sein!)
    // Array-Ausgabe für "c"
    printf("c = {");
    Vorschau2_printArray(c, 6);
    printf("};\n");

    // Array-Ausgabe für "*d"
    printf("*d = {");
    Vorschau2_printArray(*d, 6);
    printf("};\n");

    // Array-Ausgabe für "*e"
    printf("*e = {");
    Vorschau2_printArray(*e, 6);
    printf("};\n");


    // Wenn ich jetzt "d" direkt ändern wirde, dann ändere ich auch immer nur "d" (Weil "d" ja jetzt im speicher seine eigene Adresse hat)
    // In diesem Beispiel bleibt "e" also gleich.

    // Mit "d" und "e" habe ich jetzt Pointer, welche auf den Pointer von "c" zeigen.
    // Den Pointer von "c" in "d" oder "e" (also *d oder *e) kann ich dann einfach Editieren, und somit editiere ich dann auch die Adresse von "c".
    // Dafür setze ich "c" gleich "a" ("b" bleibt hierbei unangefasst und behält die Adresse und somit die original Daten)
    // Um die Daten eines Pointers (egal welchen Grades) zu ändern, muss man ihr Dereferenzieren (* vor dem Variablennamen).
        // ACHTUG: Dereferenzierung hat keinen Vorrang in Operationen. Bei Rechnungen usw. immer die Dereferenzierung einklammern z.B.: (*d)++;
    *d = a;

    // Damit hat sich "e" automatisch mitgeändert! (Weil "e" ja auch auf "die Variable" (welche auf c Zeigt) zeigt)

    // "a", "b", "c", "d" und "e" ausgeben:
    printf("%p - %p - %p - %p - %p\n", a,b,c, *d, *e);

    // Array-Ausgabe für "a"
    printf("a = {");
    Vorschau2_printArray(a, 6);
    printf("};\n");

    // Array-Ausgabe für "b"
    printf("b = {");
    Vorschau2_printArray(b, 6);
    printf("};\n");

    // Array-Ausgabe für "c"
    printf("c = {");
    Vorschau2_printArray(c, 6);
    printf("};\n");

    // Array-Ausgabe für "*d"
    printf("*d = {");
    Vorschau2_printArray(*d, 6);
    printf("};\n");

    // Array-Ausgabe für "*e"
    printf("*e = {");
    Vorschau2_printArray(*e, 6);
    printf("};\n");
}

int main() {
    Vorschau1();
    Vorschau2();
    return 0;
}
