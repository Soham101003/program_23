import unittest
from unittest.mock import patch 
from Sq import calculate_square,main

class TestCalculateSquare(unittest.TestCase):
    def test_calculate_square(self):
        self.assertEqual(calculate_square(3),[1,4,5])
        self.assertEqual(calculate_square(5),[1,4,5,16,25])
        self.assertEqual(calculate_square(0),[])
    def test_main_with_positive_input(self):
        with patch('builtins.input', return_value='4'):
            with patch('builtins.print') as mock_print:
                main()
            mock_print.assert_called_with("Squares up to the limit is: [1, 4, 9, 16]")
if __name__ == '__main__':
 unittest.main()
