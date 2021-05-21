#**1**. O que são sistemas embarcados?

      Sistemas Embarcados são um termo geral para união de hardware e software dedicado a uma determinada   
      tarefa e embarcados em determinado produto.
      
#**2**. O que são sistemas microprocesssados?

      Sistemas microprocessados são sistemas os quais todos os componentes necessários para o processamento  
      de dados esteja contido em um único chip.
      
#**3**. Apresente aplicações de sistemas embarcados:  
(*a*) Para a indústria automotiva;  
(*b*) Para eletrodomésticos;  
(*c*) Para automação industrial.

      a: Atualmente boa parte de um carro é controlado por sistemas embarcados, há a sua presença desde a  
      injeção eletrônica até a os sistemas de airbag.
      
      b: É cada vez mais difícil encontrar eletrodomésticos modernos que não possuem sistemas embarcados,  
      fornos com controladores de temperatura e temporizadores eletrônicos são um exemplo comum.
      
      c: Sistemas embarcados acompanham a indústria a muito tempo, no campo de instrumentação a maior parte  
      das soluções são pautadas em sistemas embarcados.
  

#**4**. Cite arquiteturas possíveis e as diferenças entre elas.
      
      Microcontroladores - São circuitos integrados, capazes serem reprogramados por meio de software, é 
      principalmente utilizado  para para sistemas embarcados. Geralmente contém no mínimo sua unidade de
      processamento, memória de programa e memória de dados, podem conter também periféricos, como conversores
      analógicos-digitais.
      
      GPPs - São os processadores de propósito geral, presente na maioria dos computadores desktops e laptops,  
      neles há uma maior modularização dos seus componentes, tornando mais fácil sua costumização, é fácil  
      mudar a memória RAM de um computador pessoal. Outra característica, é que geralmente nesses computadores  
      não é tão considerado as limitações físicas, tanto espaciais quanto de temperatura, devido a 
      possibilidade de maiores gabinetes e melhores sistemas de resfriamento.
      
      DSPs - São microcontroladores especializados em processamento de sinais, se destacam em relação aos 
      outros quando são utilizados para filtros digitais e analises de Fourier
      
      FPGAs - As FPGAs são placas de hardware reprogramável, utilizando de arranjos de portas reprogramáveis, 
      as FPGAs podem utilizar de processamento parelelo específico a cada caso, elevando ao máximo a 
      performance da placa, porém, isso ocasiona um custo muito elevado, restringindo seu nicho de aplicações.
      Ainda uma das maiores forças das FPGAs encontra-se na sua capacidade de prototipagem, é possível simular 
      praticamente todo tipo de hardware, uma importante parte do desenvolvimento de um ASIC é sua simulação 
      em uma FPGA.
      
      ASICs - São os chips desenvolvidos para exercer uma função específica, é desenvolvido um hardware 
      especifico que atenda as especificações do problema. O chip individual de um ASIC é extremamente mais 
      barato que outras soluções, o problema de sua utilização está em seu custo de desenvolvimento, sendo 
      muito superior a qualquer outra das tecnologias citadas, sendo assim, os ASICs são utilizados quando há 
      a necessidade de produção em larga escala, e o custo de desenvolvimento pode ser dissolvido em uma 
      quantidade imensa de unidades.
      
      SoCs - São chips que contém todos os componentes necessários para se realizar o processamento de dados, 
      desde o microprocessador até os periféricos que controlam as I/O, são similares aos microcontroladores, 
      porém, seu poder computacional se assemelha muito mais aos GPPs, e eles requerem menos periféricos externos 
      aos chips para funcionarem, é possível encontrar SoCs que possuam também FPGAs em sua arquitetura.
      
      MPSoCs - São SoCs que possuem mais de um processador em seu chip.

#**5**. Por que usamos o Raspberry Pi na disciplina, ao invés de outro system-on-chip?

      Porque é um SoC com bastante documentação, o que facilita a criação de projetos, resolução de 
      problemas; além de ter um preço relativamente acessível.
      


