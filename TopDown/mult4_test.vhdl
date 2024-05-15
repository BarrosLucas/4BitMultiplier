-- Multiplicador de 4 bits
-- Descrição em VHDL comportamental
-- Copiado de https://ashwith.wordpress.com/2011/02/07/vhdl-in-alliance-behavioral-simulations/
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mult4 is
port
(
 A     : in  std_logic_vector (3 downto 0);
 B     : in  std_logic_vector (3 downto 0);
 P     : out std_logic_vector (7 downto 0);
 --Ovf  : out std_logic;
 Vdd   : in std_logic;
 Vss   : in std_logic
);
end mult4;

architecture mult4_comportamental of mult4 is
begin
  process(A, B)
    --variable Sum_temp : unsigned (4 downto 0);
    --variable Cin_temp : unsigned (4 downto 0);
	variable Mult_temp: std_logic_vector(7 downto 0);
	variable B_temp: std_logic_vector(7 downto 0);
	begin
	Mult_temp := "00000000";
	B_temp(3 downto 0) := B;
	for i in 0 to 3 loop
		if A(i) = '1' then
			Mult_temp := shift_left(B_temp,i)+Mult_temp;
		end if;
	end loop;
    -- Ovf <= Mult_temp(7) or Mult_temp(6);
    --S         <= std_logic_vector(Sum_temp(3 downto 0));
	P         <= Mult_temp;
  end process;
end mult4_comportamental;

