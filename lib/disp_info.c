#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/flash.h>
#include <stdio.h>
#include "xprintf.h"
#include "hardware.h"

typedef struct _reg_t {
   char *regName;
   uint32_t addr;
}TReg;

const TReg regs[] ={
    // FLASH
    { .regName = "FLASH.ACR"     ,.addr = (uint32_t)(&FLASH_ACR),   },
    // RCC
    { .regName = "RCC.CR"        ,.addr = (uint32_t)(&RCC_CR),      },
    { .regName = "RCC.CFGR"      ,.addr = (uint32_t)(&RCC_CFGR),    },
    { .regName = "RCC.CSR"       ,.addr = (uint32_t)(&RCC_CSR),     },
#if defined(STM32F4)
    { .regName = "RCC.AHB1ENR"   ,.addr = (uint32_t)(&RCC_AHB1ENR), },
#elif defined(STM32L1)
    { .regName = "RCC.ICSCR"     ,.addr = (uint32_t)(&RCC_ICSCR),   },
    { .regName = "RCC.AHBENR"    ,.addr = (uint32_t)(&RCC_AHBENR),  },
#endif
    { .regName = "RCC.APB1ENR"   ,.addr = (uint32_t)(&RCC_APB1ENR), },
    { .regName = "RCC.APB2ENR"   ,.addr = (uint32_t)(&RCC_APB2ENR), },
    // TIM3
    { .regName = "TIM3.CR1"      ,.addr = (uint32_t)(&TIM3_CR1),    },
    { .regName = "TIM3.CR2"      ,.addr = (uint32_t)(&TIM3_CR2),    },
    { .regName = "TIM3.CCMR1"    ,.addr = (uint32_t)(&TIM3_CCMR1),  },
    { .regName = "TIM3.CCMR2"    ,.addr = (uint32_t)(&TIM3_CCMR2),  },
    { .regName = "TIM3.CCER"     ,.addr = (uint32_t)(&TIM3_CCER),   },
    { .regName = "TIM3.CNT"      ,.addr = (uint32_t)(&TIM3_CNT),    },
    { .regName = "TIM3.PSC"      ,.addr = (uint32_t)(&TIM3_PSC),    },
    { .regName = "TIM3.ARR"      ,.addr = (uint32_t)(&TIM3_ARR),    },
    { .regName = "TIM3.CCR1"     ,.addr = (uint32_t)(&TIM3_CCR1),   },
    { .regName = "TIM3.CCR2"     ,.addr = (uint32_t)(&TIM3_CCR2),   },
    { .regName = "TIM3.CCR3"     ,.addr = (uint32_t)(&TIM3_CCR3),   },
    { .regName = "TIM3.CCR4"     ,.addr = (uint32_t)(&TIM3_CCR4),   },
    // SPI1
    { .regName = "SPI1.CR1"      ,.addr = (uint32_t)(&SPI1_CR1),    },
    { .regName = "SPI1.CR2"      ,.addr = (uint32_t)(&SPI1_CR2),    },
    // GPIO MODER
    { .regName = "GPIOA.MODER"   ,.addr = (uint32_t)(&GPIOA_MODER), },
    { .regName = "GPIOB.MODER"   ,.addr = (uint32_t)(&GPIOB_MODER), },
    { .regName = "GPIOC.MODER"   ,.addr = (uint32_t)(&GPIOC_MODER), },
    { .regName = "GPIOD.MODER"   ,.addr = (uint32_t)(&GPIOD_MODER), },
    // GPIO AFR
    { .regName = "GPIOA.AFRL"    ,.addr = (uint32_t)(&GPIOA_AFRL), },
    { .regName = "GPIOA.AFRH"    ,.addr = (uint32_t)(&GPIOA_AFRH), },
    { .regName = "GPIOB.AFRL"    ,.addr = (uint32_t)(&GPIOB_AFRL), },
    { .regName = "GPIOB.AFRH"    ,.addr = (uint32_t)(&GPIOB_AFRH), },
    { .regName = "GPIOC.AFRL"    ,.addr = (uint32_t)(&GPIOC_AFRL), },
    { .regName = "GPIOC.AFRH"    ,.addr = (uint32_t)(&GPIOC_AFRH), },
    { .regName = "GPIOD.AFRL"    ,.addr = (uint32_t)(&GPIOD_AFRL), },
    { .regName = "GPIOD.AFRH"    ,.addr = (uint32_t)(&GPIOD_AFRH), },
    // GPIO PUDR
    { .regName = "GPIOA.PUPDR"   ,.addr = (uint32_t)(&GPIOA_PUPDR), },
    { .regName = "GPIOB.PUPDR"   ,.addr = (uint32_t)(&GPIOB_PUPDR), },
    { .regName = "GPIOC.PUPDR"   ,.addr = (uint32_t)(&GPIOC_PUPDR), },
    { .regName = "GPIOD.PUPDR"   ,.addr = (uint32_t)(&GPIOD_PUPDR), },
    // GPIO OTYPER
    { .regName = "GPIOA.OTYPER"  ,.addr = (uint32_t)(&GPIOA_OTYPER), },
    { .regName = "GPIOB.OTYPER"  ,.addr = (uint32_t)(&GPIOB_OTYPER), },
    { .regName = "GPIOC.OTYPER"  ,.addr = (uint32_t)(&GPIOC_OTYPER), },
    { .regName = "GPIOD.OTYPER"  ,.addr = (uint32_t)(&GPIOD_OTYPER), },
    // GPIO OSPEEDR
    { .regName = "GPIOA.OSPEEDR" ,.addr = (uint32_t)(&GPIOA_OSPEEDR), },
    { .regName = "GPIOB.OSPEEDR" ,.addr = (uint32_t)(&GPIOB_OSPEEDR), },
    { .regName = "GPIOC.OSPEEDR" ,.addr = (uint32_t)(&GPIOC_OSPEEDR), },
    { .regName = "GPIOD.OSPEEDR" ,.addr = (uint32_t)(&GPIOD_OSPEEDR), },
    // GPIO ODR
    { .regName = "GPIOA.ODR"     ,.addr = (uint32_t)(&GPIOA_ODR), },
    { .regName = "GPIOB.ODR"     ,.addr = (uint32_t)(&GPIOB_ODR), },
    { .regName = "GPIOC.ODR"     ,.addr = (uint32_t)(&GPIOC_ODR), },
    { .regName = "GPIOD.ODR"     ,.addr = (uint32_t)(&GPIOD_ODR), },

    // WATCH DOG
    { .regName = NULL ,.addr = 0, },
};

void regInfoCore(void) {
    static TReg *pReg = (TReg*)regs;
    static bool fTitle = true;
    static int32_t prev = 0;
    if( (millis() - prev ) > 200){
        prev = millis();
        if( fTitle ) {
            fTitle = false;
            xprintf("\n ========== Reg info ==========");
        }
        if( pReg->regName != NULL ) {
            xprintf("\n%-15s = %08X (%08X)"
                    ,pReg->regName,*((volatile uint32_t *)(pReg->addr)),pReg->addr);
            pReg++;
        }else{
          pReg = (TReg*)regs;
          fTitle = true;
        }
    }
}

