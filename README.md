# simpleCSMA
Implementazione del protocollo CSMA/CA con rilevazione delle collisioni basata sulla perdita o sulla non correttezza degli ack inviati dal ricevitore. Si adopera su un bus interfacciato con un transceiver RS485. Il transceiver provato è un MAX485 con piedino di controllo della direzione. Dovrebbe funzionare anche con un transceiver col controllo automatico della direzione (piedino con una impostazione qualsiasi).
Sostanzialmente è un rimaneggiamento del codice citato di seguito:
 * @file 	ModbusRtu.h
 * @version     1.21
 * @date        2016.02.21
 * @author 	Samuel Marco i Armengol
 * @contact     sammarcoarmengol@gmail.com
 * @contribution Helium6072
 
 Trama: |---DA---|---SA---|---GROUP---|---SI---|---BYTE_CNT---|---PAYLOAD---|---CRC---|
 
        |---1B---|---1B---|----1B-----|---1B---|------1B------|---VARIABLE--|---2B----|
 
 DA: destination address - 1byte (FF indirizzo di broadcast)
 
 SA: source addresss - 1byte
 
 Group: group addresss - 1byte (per inviare a tutti membri del gruppo DA deve essere FF)
 
 SI: service identifier (ACK, MSG)s - 1byte
 
 BYTE_CNT: numero byte complessivi (+payload -CRC)s - 1byte
 
 CRC: Cyclic Redundancy Check - 2byte (calcolati su tutto il messaggio)
