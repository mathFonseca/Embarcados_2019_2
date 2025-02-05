#include "uart.h"

void printchar(char c){//Envio UM caracter
	while((UART0->FR & (1<<5)) != 0);
	UART0->DR = c;	//Escreve na saida o conteudo de c
}

void UARTprintstring(char * string){//Envia uma String
	while(*string){//enquanto houver elementos na string
		printchar(*(string++));//Envia caracteres para a saida
	}
}

/*Leitura de elementos*/
char readchar(void){//leitura de caractere
	char c;
	// verifica se esta receber
	while((UART0->FR & (1<<4)) != 0);
	//Recebe caracteres para a saida
	c = UART0->DR;
	return c;
}

// Inicialização UART
void inicia_UART(){
		uint32_t ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                              SYSCTL_OSC_MAIN |
                                              SYSCTL_USE_PLL |
                                              SYSCTL_CFG_VCO_480),
                                              120000000); // PLL em 120MHz
		
		static unsigned long g_ulBase = 0;
		static const unsigned long g_ulUARTBase[3] ={UART0_BASE, UART1_BASE, UART2_BASE};
		static const unsigned long g_ulUARTPeriph[3] ={SYSCTL_PERIPH_UART0, SYSCTL_PERIPH_UART1, SYSCTL_PERIPH_UART2};
    
		// Habilita o periferico da UART0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    // Inicia as configuracoes para o port A
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    // Delay de inicialização
    SysCtlDelay(3);
    // Configura PA0 como RX
    // Configura PA1 como Tx
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    // Delay de inicialização
    SysCtlDelay(3);
		GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    
    // Config UART
    //UARTStdioConfig(0, 115200, ui32SysClock);
		
		//
    // Select the base address of the UART.
    //
    g_ulBase = g_ulUARTBase[0];
		
    //
    // Enable the UART peripheral for use.
    //
    MAP_SysCtlPeripheralEnable(g_ulUARTPeriph[0]);

    //
    // Configure the UART for 115200, n, 8, 1
    //
    MAP_UARTConfigSetExpClk(g_ulBase, ui32SysClock, 115200,
                            (UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_WLEN_8));
		
		
		
		
		
		//
    // Enable the UART operation.
    //
    MAP_UARTEnable(g_ulBase);
		
		
		// Config de interrupção
		UART0 ->	CTL &= ~(1<<0);							//Disable a UART, para fazer as configuracoes 
		UART0 ->	LCRH = (0x3<<5);						//palavra de 8 bits sem paridade 
		UART0 ->	IFLS |=(1<<4);							//Uso default
		UART0 ->	IM |=(1<<4);								//Habilita interrupcoes 
		UART0 ->	CTL = (1<<0)|(1<<8)|(1<<9);	//Habilita a UART com Rx&Tx
		NVIC -> ISER[0] |= (1<<5);						//Habilita interrupcoes de UART0 no vetor de interrupcoes
		__NVIC_SetPriority(UART0_IRQn,1<<5);
		
    // Configuracoes do UART
		// Delay de inicialização
    SysCtlDelay(30);

    // Envio de mensagem para a UART
    UARTprintstring("\033[2J");
		UARTprintstring("UART OK!\r\n");
    UART_printMenu();
}
//------------UART_InString------------
// Accepts ASCII characters from the serial port
//    and adds them to a string until <enter> is typed
//    or until max length of the string is reached.
// It echoes each character as it is inputted.
// If a backspace is inputted, the string is modified
//    and the backspace is echoed
// terminates the string with a null character
// uses busy-waiting synchronization on RDRF
// Input: pointer to empty buffer, size of buffer
// Output: Null terminated string
// -- Modified by Agustinus Darmawan + Mingjie Qiu --
void UART_InString(char *bufPt, unsigned short max) {
int length=0;
char character;
character = readchar();
  
	while(character != 13){
    if(character == BACKSPACE){
      if(length){
        bufPt--;
        length--;
        printchar(BACKSPACE);
      }
    }
    else if(length < max){
      *bufPt = character;
      bufPt++;
      length++;
      printchar(character);
    }
    character = readchar();
  }
  *bufPt = 0;

	return;
}


// Menu 1 - UART
void UART_printMenu(){
	UARTprintstring(" 1 - Senoidal");
	UARTprintstring("\n\r");
	UARTprintstring(" 2 - Quadrada");
	UARTprintstring("\n\r");
	UARTprintstring(" 3 - Dente de serra");
	UARTprintstring("\n\r");
	UARTprintstring(" 4 - Triangular");
	UARTprintstring("\n\r");
	UARTprintstring(" 5 - Trapezoidal");
	UARTprintstring("\n\r");
	UARTprintstring("----------------");
	UARTprintstring("\n\r");
	UARTprintstring(" W - +5Hz | w - +1Hz");
	UARTprintstring("\n\r");
	UARTprintstring(" S - -5Hz | s - -1Hz");
	UARTprintstring("\n\r");
	UARTprintstring(" D - +1V | d - +0.1V ");
	UARTprintstring("\n\r");
	UARTprintstring(" A - -1V | a - -0.1V ");
	UARTprintstring("\n\r");

}
// Menu 1 - UART
void UART_printMenu_A(){
	UARTprintstring(" 1 - Senoidal");
	UARTprintstring("\n\r");
	UARTprintstring(" 2 - Quadrada");
	UARTprintstring("\n\r");	
	UARTprintstring(" 3 - Dente de serra");
	UARTprintstring("\n\r");
	UARTprintstring(" 4 - Triangular");
	UARTprintstring("\n\r");
	UARTprintstring(" 5 - Trapezoidal");
	UARTprintstring("\n\r");	
	UARTprintstring(" ----------------------------------");
	UARTprintstring("\n\r");
}
// Menu 2 - UART
void UART_printMenu_BC(){
	UARTprintstring(" + - Incrementa");
	UARTprintstring("\n\r");
	UARTprintstring(" - - Decrementa");
	UARTprintstring("\n\r");
	UARTprintstring(" ----------------------------------");
	UARTprintstring("\n\r");	
}
