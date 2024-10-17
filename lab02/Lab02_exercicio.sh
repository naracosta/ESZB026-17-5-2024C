LED_GPIO_Y=16  # Usar uma variavel facilita alteracoes futuras na porta usada
LED_GPIO_R=20
LED_GPIO_G=21

#  habilita
echo $LED_GPIO_Y >> "/sys/class/gpio/export"
echo $LED_GPIO_R >> "/sys/class/gpio/export"
echo $LED_GPIO_G >> "/sys/class/gpio/export"
sleep 0.1
echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_Y/direction"
echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_R/direction"
echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_G/direction"
sleep 0.1

i=0
while [ $i -lt 5 ]; do
    # acende o vermelho por 2s
    echo 1 > "/sys/class/gpio/gpio$LED_GPIO_R/value"
    sleep 2
    echo 0 > "/sys/class/gpio/gpio$LED_GPIO_R/value"

    # acende o verde por 1s
    echo 1 > "/sys/class/gpio/gpio$LED_GPIO_G/value"
    sleep 1
    echo 0 > "/sys/class/gpio/gpio$LED_GPIO_G/value"

    # acende o amarelo por 1s
    echo 1 > "/sys/class/gpio/gpio$LED_GPIO_Y/value"
    sleep 1
    echo 0 > "/sys/class/gpio/gpio$LED_GPIO_Y/value"

    i=$((i + 1))  # Incrementa o contador
done

# desabilita
echo $LED_GPIO_Y >> "/sys/class/gpio/unexport"
echo $LED_GPIO_R >> "/sys/class/gpio/unexport"
echo $LED_GPIO_G >> "/sys/class/gpio/unexport"
